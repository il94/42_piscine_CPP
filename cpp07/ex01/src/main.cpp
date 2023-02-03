#include "../include/iter.h"

// template< typename T >
// void	show(T& x)
// {
// 	std::cout << T << std::endl;
// }


int main( void )
{
	int*	array = new int [3];

	array[0] = 0;
	array[1] = 1;
	array[2] = 2;

	iter(array, 3, show);

	// std::cout << std::endl;
	// std::cout << "===================================" << std::endl;
	// std::cout << std::endl;

	return (0);
}