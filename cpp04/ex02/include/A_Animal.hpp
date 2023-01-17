#ifndef A_ANIMAL
#define A_ANIMAL

#include <iostream>

#include "Brain.hpp"

class A_Animal
{
	public :

	/* Constructors */
	A_Animal();
	A_Animal(std::string type);
	A_Animal(const A_Animal&);
	virtual ~A_Animal();

	/* Overloads */
	A_Animal&	operator=(const A_Animal&);

	/* Methods */
	virtual void	makeSound( void ) const = 0;
	void			wants( void ) const;

	/* Accessors */
	std::string	getType( void ) const;

	protected :

	/* Attributes */
	std::string	_type;
	Brain*	_brain;
};

#endif