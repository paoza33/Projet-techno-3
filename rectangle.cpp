#include "rectangle.h"
#include "ei_draw.h"

#include <string>
#include <iostream>

using namespace std;

Rectangle::Rectangle(ei_point_t point, ei_size_t size, Point speed): 
    Shape(point, size),
    _speed(5,5){
}

Rectangle::Rectangle() : _point({50,50}), _size({100,100}), _speed(5,5){

}

Rectangle::~Rectangle(){
}

void Rectangle::draw(ei_surface_t surface){

    ei_color_t black = { 0x00, 0x00, 0x00, 0xff };

    ei_linked_point_t	points[4];
    points[0].point.x = _point.x;
    points[0].point.y = _point.y;
    points[1].point.x = _point.x + _size.width;
    points[1].point.y = _point.y;
    points[2].point.x = _point.x + _size.width;
    points[2].point.y = _point.y + _size.height;
    points[3].point.x = _point.x;
    points[3].point.y = _point.y + _size.height;

    for (int i = 0; i < 4; i++) {
        if (i < 3)
            points[i].next = &(points[i + 1]);
        else
            points[i].next = NULL;
    }
    ei_draw_polygon(surface, points, black);
}

string Rectangle::getName(){
    return "Rectangle";
}

ei_point_t Rectangle::get_point() const{
    return _point;
}

void Rectangle::set_point(ei_point_t point){
    _point = point;
}

void Rectangle::setPosition(const Point &v){
    _point.x = v.get_x();
    _point.y = v.get_y();
}

void Rectangle::setPosition(float x, float y){
    _point.x = x;
    _point.y = y;
}

ei_size_t Rectangle::get_size() const{
    return _size;
}

void Rectangle::set_size(ei_size_t size){
    _size = size;
}

void Rectangle::setSpeed(const Point& speed){
    _speed = speed;
}

