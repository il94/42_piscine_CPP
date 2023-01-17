#ifndef MATERIAICE
#define MATERIAICE

#include <iostream>

#include "A_Materia.hpp"

class MateriaIce : public A_Materia
{
	public :

	/* Constructors */
	MateriaIce();
	MateriaIce(const MateriaIce&);
	~MateriaIce();

	/* Overloads */
	MateriaIce&	operator=(const MateriaIce&);

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	/* Accessors */
	

	private :

	/* Attributes */
	

};

#endif