#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include "I_character.hpp"
#include "MateriaIce.hpp"
#include "MateriaCure.hpp"

class Character : public I_Character
{
	public :

	/* Constructors */
	Character();
	Character(const std::string &);
	Character(const Character&);
	~Character();

	/* Overloads */
	Character&	operator=(const Character&);

	/* Methods */
	virtual std::string const&	getName( void ) const;
	virtual void				equip(A_Materia* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, I_Character& target);

	/* Accessors */
	

	private :

	/* Attributes */
	std::string	_name;	
	A_Materia	*_inventory[4];
	int			_countMaterias;
};

#endif