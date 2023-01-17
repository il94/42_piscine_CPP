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
	A_Animal	*a_animals[SIZE_ARRAY];

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (i % 2 == 0)
			a_animals[i] = new Dog;
		else
			a_animals[i] = new Cat;
		std::cout << std::endl;
	}
	std::cout << std::endl;


	// A_Animal	copyA_Animal(*a_animals[0]); //a_animals[0] is a dog
	// A_Animal	assignA_Animal;
	// assignA_Animal = *a_animals[0];
	// std::cout << std::endl;
	// std::cout << std::endl;


	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		a_animals[i]->wants();
		a_animals[i]->wants();
		a_animals[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		delete a_animals[i];
		std::cout << std::endl;
	}

	// copyA_Animal.wants();
	// assignA_Animal.wants();
	return 0;
}