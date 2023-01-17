#ifndef WRONGCAT
#define WRONGCAT

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :

	/* Constructors */
	WrongCat();
	WrongCat(const WrongCat&);
	~WrongCat();

	/* Overloads */
	WrongCat&	operator=(const WrongCat&);

	/* Methods */
	void	makeSound( void ) const;
};

#endif