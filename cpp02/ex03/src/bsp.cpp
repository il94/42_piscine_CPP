#include "../include/Point.hpp"

static Fixed	vectorProduct(const Point &a, const Point &b, const Point &m)
{
	return (((a.getX() - m.getX()) * (b.getY() - m.getY())) - ((a.getY() - m.getY()) * (b.getX() - m.getX())));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab = vectorProduct(a, b, point);
	Fixed bc = vectorProduct(b, c, point);
	Fixed ca = vectorProduct(c, a, point);

	return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}