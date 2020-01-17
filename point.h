#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point{
    public:
        Point(int x = 0, int y = 0): _x(x), _y(y){}
        Point(Point const& other);  //pointeur pour pouvoir le modifier

        virtual ~Point();

        //getter setter
        int get_x() const;
        int get_y() const;
        void set_x(int x);
        void set_y(int y);

        //surcharge operator
        
        Point& operator+=(const Point& p);
        Point& operator-=(Point const& p);
        Point& operator*=(Point const& p);
        Point& operator*=(int const& i);
        void afficher(std::ostream &flux) const;
        

    private:
        int _x;
        int _y;
};

Point operator+(const Point& p, const Point& p2);
Point operator-(const Point& p, const Point& p2);
Point operator*(const Point& p, const Point& p2);
Point operator*(const Point& p, int const& i);

#endif