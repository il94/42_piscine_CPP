#ifndef DOG
#define DOG

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal
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