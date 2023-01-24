#ifndef MATERIAICE
#define MATERIAICE

#include <iostream>

#include "A_Materia.hpp"
#include "I_character.hpp"

class MateriaIce : public A_Materia
{
	public :

	/* Constructors */
	MateriaIce();
	~MateriaIce();

	/* Overloads */

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	/* Accessors */
	

	private :

	/* Overloads */
	MateriaIce&	operator=(const MateriaIce&);

	/* Methods */
	MateriaIce(const MateriaIce&);
	
	/* Attributes */

};

#endif