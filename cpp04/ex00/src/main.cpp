#include <iostream>
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

// int main( void )
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;

// 	return (0);
// }

int main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << meta->getType() << " : ";
	meta->makeSound();
	std::cout << std::endl;
	std::cout << dog->getType() << " : ";
	dog->makeSound();
	std::cout << cat->getType() << " : ";
	cat->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << wrongAnimal->getType() << " : ";
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << " : ";
	wrongCat->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;


	delete meta;
	std::cout << std::endl;

	delete cat;
	delete dog;
	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;

	return (0);
}