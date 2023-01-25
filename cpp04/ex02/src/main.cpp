#include <iostream>
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

#define	SIZE_ARRAY 4

// int main( void )
// {
// 	const A_Animal* j = new Dog();
// 	const A_Animal* i = new Cat();

// 	delete j;
// 	delete i;

// 	return (0);
// }

int main( void )
{
	A_Animal	*A_Animals[SIZE_ARRAY];

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (i % 2 == 0)
			A_Animals[i] = new Dog;
		else
			A_Animals[i] = new Cat;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		A_Animals[i]->wants();
		A_Animals[i]->wants();
		A_Animals[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		delete A_Animals[i];
		std::cout << std::endl;
	}

	return 0;
}