#ifndef I_CHARACTER
#define I_CHARACTER

#include <iostream>

#include "A_Materia.hpp"

class A_Materia;

class I_Character
{
	public :

	/* Constructors */
	virtual ~I_Character();

	/* Methods */
	virtual std::string const&	getName( void ) const = 0;
	virtual void				equip(A_Materia* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, I_Character& target) = 0;

	/* Accessors */
	

	private :

	/* Attributes */

};

#endif