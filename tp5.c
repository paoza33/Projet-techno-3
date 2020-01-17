#include <stdlib.h>
#include <stdio.h>
#include <allegro5/keycodes.h>
#include "ei_types.h"
#include "ei_main.h"
#include "ei_draw.h"
#include "ei_event.h"
#include "hw_interface.h"

int ei_main(int argc, char** argv)
{
    ei_surface_t main_window = NULL;
    ei_size_t main_window_size = {640, 480};
    ei_event_t event;
    ei_bool_t do_exit = EI_FALSE;
    ei_color_t white = {0xff, 0xff, 0xff, 0xaa};
    ei_color_t red = { 0xff, 0x00, 0x00, 0xff };
    ei_surface_t image;
    ei_size_t image_size;
    ei_point_t draw_pos = {0, 0};

    // Init acces to hardware.
    hw_init();

    // Create the main window.
    main_window = hw_create_window(&main_window_size, EI_FALSE);

    // Load ball image
    image = hw_image_load(DATA_DIR"ball.png");
    image_size = hw_surface_get_size(image);


    hw_surface_lock(main_window);
    ei_fill(main_window, &white, EI_FALSE);
    ei_copy_surface(main_window, image, &draw_pos, EI_TRUE);
    hw_surface_unlock(main_window);
    hw_surface_update_rects(NULL);

    double time = hw_now();

    // Wait for an event.
    event.type = ei_ev_none;
    while (do_exit != EI_TRUE) {
        hw_event_wait_next(&event);
        
    }

    // Free hardware resources.
    hw_quit();

    // Terminate program with no error code.
    return 0;
}
