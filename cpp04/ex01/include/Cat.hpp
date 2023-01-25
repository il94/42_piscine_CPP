#ifndef CAT
#define CAT

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public :

	/* Constructors */
	Cat();
	Cat(const Cat&);
	virtual ~Cat();

	/* Overloads */
	Cat&	operator=(const Cat&);

	/* Methods */
	void	makeSound( void ) const;
	void	wants( void ) const;

	private :

	Brain*	_brain;
};

#endif