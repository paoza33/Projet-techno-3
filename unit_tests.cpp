#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "ei_types.h"
#include "ei_draw.h"
#include "ei_main.h"
#include "hw_interface.h"

ei_surface_t main_window = NULL;
ei_size_t main_window_size;

TEST_CASE("create_window", "[unit]")
{
    main_window_size.width = 640;
    main_window_size.height = 480;
    
    main_window = hw_create_window(&main_window_size, EI_FALSE);
    ei_size_t size = hw_surface_get_size(main_window);
    REQUIRE( main_window != NULL );
    REQUIRE(size.width == 640);
    REQUIRE(size.height == 480);
}

TEST_CASE("ei_fill", "[unit]")
{
    ei_color_t red = {0xff, 0x00, 0x00, 0xff}, query_color;
    
    ei_point_t point;
    
    hw_surface_lock(main_window);
    ei_fill(main_window, &red, EI_FALSE);
    for (int x=0; x<main_window_size.width; x++)
        for (int y=0; y<main_window_size.height; y++) {
            point.x = x;
            point.y = y;
            query_color = hw_get_pixel(main_window, point);
            REQUIRE( query_color.red == red.red );
            REQUIRE( query_color.green == red.green );
            REQUIRE( query_color.blue == red.blue );
        }
    hw_surface_unlock(main_window);
}
TEST_CASE("fill_default", "[unit]"){
    
    ei_point_t point;
    ei_color_t query_color;
    ei_size_t surface_size ={300,300};
    
    ei_surface_t surface = hw_surface_create(main_window, &surface_size );
    
    
    
    hw_surface_lock(surface);
    ei_fill(surface, NULL, EI_FALSE);
    
    for (int x=0; x<surface_size.width; x++)
        for (int y=0; y<surface_size.height; y++) {
            point.x = x;
            point.y = y;
            query_color = hw_get_pixel(surface, point);
            REQUIRE( query_color.red == ei_font_default_color.red );
            REQUIRE( query_color.green == ei_font_default_color.green );
            REQUIRE( query_color.blue == ei_font_default_color.blue );
        }
    
    hw_surface_unlock(surface);
    hw_surface_free(surface);
}



TEST_CASE("ei_copy_surface", "[unit]"){
    ei_point_t point, pos;
    ei_size_t surface_size ={300,300};
    ei_color_t green={0,255,0,255};
    ei_color_t query_color;

    ei_surface_t surface = hw_surface_create(main_window, &surface_size );
    
    hw_surface_lock(main_window);
    ei_fill(main_window, NULL, EI_FALSE);
    
    hw_surface_lock(surface);
    ei_fill(surface, &green, EI_FALSE);
    pos.x = 60;
    pos.y = 100;
    ei_copy_surface(main_window, surface,&pos, EI_FALSE);
    
    
    for (int x=0; x<main_window_size.width; x++)
        for (int y=0; y<main_window_size.height; y++) {
            point.x = x;
            point.y = y;
            query_color = hw_get_pixel(main_window, point);
            if (x>=60 && x<360 && y>=100 && y<400) {
                REQUIRE( query_color.red == green.red );
                REQUIRE( query_color.green == green.green );
                REQUIRE( query_color.blue == green.blue );
            }
            else{
                REQUIRE( query_color.red == ei_font_default_color.red );
                REQUIRE( query_color.green == ei_font_default_color.green );
                REQUIRE( query_color.blue == ei_font_default_color.blue );
            }
        }
    hw_surface_unlock(surface);
    hw_surface_free(surface);
    
    hw_surface_unlock(main_window);
    


}



int ei_main(int argc, char* argv[])
{
    // Init acces to hardware.
    hw_init();
    
    int result = Catch::Session().run( argc, argv );
    
    // Free hardware resources.
    hw_quit();
    
    return result;
}