#ifndef ITER_H
#define ITER_H

#include <iostream>

template< typename W >
void	show(W x)
{
	std::cout << x << std::endl;
}

template< typename T, typename U, typename V >
void	iter(T* array, U sizeArray, V function)
{
	for (int i = 0; i < sizeArray; i++)
		function(array[i]);
}

#endif