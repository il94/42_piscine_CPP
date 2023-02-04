#ifndef ITER_H
#define ITER_H

#include <iostream>

void	badDisplay(int element);

template< typename W>
void	display(W element)
{
	std::cout << element << ", but displayed by an INSANE TEMPLATE BRO" << std::endl;
}

template< typename T, typename U, typename V>
void	iter(T *array, U sizeArray, V function)
{
	for (int i = 0; i < sizeArray; i++)
		function(array[i]);
}

#endif