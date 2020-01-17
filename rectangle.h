#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ei_types.h"
#include "hw_interface.h"
#include "point.h"
#include "shape.h"

class Rectangle : public Shape
{
    public:
        //! constructor
        Rectangle(ei_point_t point, ei_size_t size, Point speed);
        Rectangle();
        virtual ~Rectangle();

        //getter setter
        void draw(ei_surface_t surface);
        string getName();
        ei_point_t get_point() const;
        void set_point(ei_point_t point);
        void setPosition(const Point &v);
        void setPosition(float x, float y);
        ei_size_t get_size() const;
        void set_size(ei_size_t size);
        void setSpeed(const Point& speed);

    private:
        ei_point_t _point;
        ei_size_t _size;
        Point _speed;
};

#endif