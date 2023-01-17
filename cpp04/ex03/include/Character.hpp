#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include "I_character.hpp"

class Character : public I_Character
{
	public :

	/* Constructors */
	Character();
	Character(const Character&);
	~Character();

	/* Overloads */
	Character&	operator=(const Character&);

	/* Methods */
	

	/* Accessors */
	

	private :

	/* Attributes */
	

};

#endif