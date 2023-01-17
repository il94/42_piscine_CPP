#ifndef DOG
#define DOG

#include <iostream>

#include "A_Animal.hpp"

class Dog : public A_Animal
{
	public :

	/* Constructors */
	Dog();
	Dog(const Dog&);
	~Dog();

	/* Overloads */
	Dog&	operator=(const Dog&);

	/* Methods */
	void	makeSound( void ) const;
};

#endif