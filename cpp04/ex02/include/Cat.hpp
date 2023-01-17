#ifndef CAT
#define CAT

#include <iostream>

#include "A_Animal.hpp"

class Cat : public A_Animal
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