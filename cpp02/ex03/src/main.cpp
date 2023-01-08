#include "../include/Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	std::cout << "[1] = " << bsp(Point(35, 80), Point(84, 8), Point(21, 27), Point(46, 44)) << std::endl;
	std::cout << "[2] = " << bsp(Point(35, 80), Point(84, 8), Point(21, 27), Point(23, 21)) << std::endl;
	std::cout << "[3] = " << bsp(Point(35, 80), Point(84, 8), Point(21, 27), Point(57, 16)) << std::endl;
	std::cout << "[4] = " << bsp(Point(35, 80), Point(84, 8), Point(21, 27), Point(78, 13)) << std::endl;
	std::cout << "[5] = " << bsp(Point(35, 80), Point(84, 8), Point(21, 27), Point(86, 85)) << std::endl;
	std::cout << "[6] = " << bsp(Point(35, 80), Point(84, 8), Point(21, 27), Point(35, 78)) << std::endl;
	std::cout << "[7] = " << bsp(Point(35, 80), Point(84, 8), Point(21, 27), Point(21, 27)) << std::endl;
	return (0);
}
