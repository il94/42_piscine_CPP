#ifndef MATERIAICE
#define MATERIAICE

#include <iostream>

#include "A_Materia.hpp"
#include "I_Character.hpp"

class MateriaIce : public A_Materia
{
	public :

	/* Constructors */
	MateriaIce();
	~MateriaIce();

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	private :

	/* Constructors */
	MateriaIce(const MateriaIce&);

	/* Overloads */
	MateriaIce&	operator=(const MateriaIce&);
};

#endif