#ifndef DOG
#define DOG

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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