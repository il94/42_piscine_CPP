#ifndef POINT
#define POINT

#include "Fixed.hpp"

class Point
{
	public :

	Point();
	Point(const float x, const float y);
	Point(const Point&);
	~Point();

	Point&	operator=(const Point&);

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

	private :

	const Fixed	_x;
	const Fixed	_y;
};

#endif