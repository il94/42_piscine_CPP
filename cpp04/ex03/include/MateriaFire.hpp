#ifndef MATERIAFIRE
#define MATERIAFIRE

#include <iostream>

#include "A_Materia.hpp"
#include "I_Character.hpp"

class MateriaFire : public A_Materia
{
	public :

	/* Constructors */
	MateriaFire();
	~MateriaFire();

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	private :

	/* Constructors */
	MateriaFire(const MateriaFire&);

	/* Overloads */
	MateriaFire&	operator=(const MateriaFire&);
};

#endif