#include "point.h"

#include <string>

using namespace std;



Point::Point(Point const& other): _x(other._x), _y(other._y){}  

Point::~Point(){}

int Point::get_x() const{
    return _x;
}

void Point::set_x(int x){
    _x = x;
}

int Point::get_y() const{
    return _y;
}

void Point::set_y(int y){
    _y = y;
}

Point &Point::operator+=(const Point &c){
    _x += c._x;
    _y += c._y;
    return *this;
}

Point operator+(const Point &p, const Point& p2){
    Point p3(p);
    p3 += p2;
    return p3;
}

Point& Point::operator-=(const Point& p){
    _x -= p._x;
    _y -= p._y;
    return *this;
}

Point operator-(const Point &p, const Point& p2){
    Point p3(p);
    p3 -= p2;
    return p3;
}

Point& Point::operator*=(const Point& p){
    _x *= p._x;
    _y *= p._y;
    return *this;
}

Point& Point::operator*=(int const& i){
    _x *= i;
    _y *= i;
    return *this;
}

Point operator*(const Point &p, const Point& p2){
    Point p3(p);
    p3 *= p2;
    return p3;
}

Point operator*(const Point& p, int const& i){
    Point p3(p);
    p3 *= i;
    return p3;
}

void Point::afficher(std::ostream &flux) const{
    flux << "[" << _x << ", " << _y << "]";
}

std::ostream &operator<<(std::ostream &flux, Point const& p)
{
    p.afficher(flux);
    return flux;
}
