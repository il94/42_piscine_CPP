#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0){
}

Point::Point(const float x, const float y) : _x(x), _y(y){
}

Point::Point(const Point& src){
	*this = src;
}

Point::~Point(){
}

Point&	Point::operator=(const Point &src)
{
	Fixed *x = (Fixed *)&this->_x;
	Fixed *y = (Fixed *)&this->_y;
	
	*x = src._x;
	*y = src._y;
	return *this;
}

Fixed	Point::getX( void ) const{
	return (_x);
}

Fixed	Point::getY( void ) const{
	return (_y);
}