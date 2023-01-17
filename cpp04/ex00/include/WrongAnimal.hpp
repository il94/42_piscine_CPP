#ifndef WRONGANIMAL
#define WRONGANIMAL

#include <iostream>

class WrongAnimal
{
	public :

	/* Constructors */
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal&);
	virtual ~WrongAnimal();

	/* Overloads */
	WrongAnimal&	operator=(const WrongAnimal&);

	/* Methods */
	void	makeSound( void ) const;

	/* Accessors */
	std::string	getType( void ) const;

	protected :

	/* Attributes */
	std::string	_type;

};

#endif