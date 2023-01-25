#include <iostream>
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

#define	SIZE_ARRAY 4

// int main( void )
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j;
// 	delete i;

// 	return (0);
// }

int main( void )
{
	Animal	*animals[SIZE_ARRAY];

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		animals[i]->wants();
		animals[i]->wants();
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	return 0;
}