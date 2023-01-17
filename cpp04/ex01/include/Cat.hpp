#ifndef CAT
#define CAT

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal
{
	public :

	/* Constructors */
	Cat();
	Cat(const Cat&);
	~Cat();

	/* Overloads */
	Cat&	operator=(const Cat&);

	/* Methods */
	void	makeSound( void ) const;
};

#endif