#ifndef BRAIN
#define BRAIN

#include <iostream>
#include <cstdlib>

class Brain
{
	public :

	/* Constructors */
	Brain();
	Brain(const Brain&);
	~Brain();

	/* Overloads */
	Brain&	operator=(const Brain&);

	/* Methods */
	std::string	getRandomIdea( void ) const;

	/* Accessors */
	

	private :

	/* Attributes */
	std::string	_ideas[100];

};

#endif