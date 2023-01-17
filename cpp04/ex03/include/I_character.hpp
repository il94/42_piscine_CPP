#ifndef I_CHARACTER
#define I_CHARACTER

#include <iostream>

#include "A_Materia.hpp"

class I_Character
{
	public :

	/* Constructors */
	I_Character();
	I_Character(const I_Character&);
	virtual ~I_Character();

	/* Overloads */
	I_Character&	operator=(const I_Character&);

	/* Methods */
	virtual std::string const&	getName( void ) const = 0;
	virtual void				equip(A_Materia* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, I_Character& target) = 0;

	/* Accessors */
	

	private :

	/* Attributes */
	A_Materia	*inventory;

};

#endif