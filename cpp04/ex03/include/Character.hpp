#ifndef CHARACTER
#define CHARACTER

#include <iostream>

#include "I_Character.hpp"
#include "A_Materia.hpp"
#include "MateriaIce.hpp"
#include "MateriaCure.hpp"
#include "MateriaFire.hpp"
#include "MateriaLightning.hpp"


class Character : public I_Character
{
	public :

	/* Constructors */
	Character(const std::string &);
	Character(const Character&);
	~Character();

	/* Overloads */
	Character&	operator=(const Character&);

	/* Methods */
	virtual void				equip(A_Materia* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, I_Character& target);

	/* Accessors */
	virtual std::string const&	getName( void ) const;
	
	private :

	/* Constructors */
	Character();

	/* Attributes */
	std::string	_name;	
	A_Materia	*_inventory[4];
	int			_countMaterias;
	A_Materia	*_throwed;
	// int			_countThrowedMaterias;
};

#endif