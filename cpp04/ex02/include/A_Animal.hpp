#ifndef A_ANIMAL
#define A_ANIMAL

#include <iostream>

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
	virtual void	wants( void ) const;

	/* Accessors */
	std::string	getType( void ) const;

	protected :

	/* Attributes */
	std::string	_type;
};

#endif