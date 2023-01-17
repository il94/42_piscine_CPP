#ifndef ANIMAL
#define ANIMAL

#include <iostream>

#include "Brain.hpp"

class Animal
{
	public :

	/* Constructors */
	Animal();
	Animal(std::string type);
	Animal(const Animal&);
	virtual ~Animal();

	/* Overloads */
	Animal&	operator=(const Animal&);

	/* Methods */
	virtual void	makeSound( void ) const;
	void			wants( void ) const;

	/* Accessors */
	std::string	getType( void ) const;

	protected :

	/* Attributes */
	std::string	_type;
	Brain*	_brain;
};

#endif