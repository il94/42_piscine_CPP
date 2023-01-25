#ifndef DOG
#define DOG

#include <iostream>

#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
	public :

	/* Constructors */
	Dog();
	Dog(const Dog&);
	virtual ~Dog();

	/* Overloads */
	Dog&	operator=(const Dog&);

	/* Methods */
	void	makeSound( void ) const;
	void	wants( void ) const;

	private :

	Brain*	_brain;
};

#endif