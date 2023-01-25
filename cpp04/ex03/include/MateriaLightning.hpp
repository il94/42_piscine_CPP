#ifndef MATERIALIGHTNING
#define MATERIALIGHTNING

#include <iostream>

#include "A_Materia.hpp"
#include "I_Character.hpp"

class MateriaLightning : public A_Materia
{
	public :

	/* Constructors */
	MateriaLightning();
	~MateriaLightning();

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	private :

	/* Constructors */
	MateriaLightning(const MateriaLightning&);

	/* Overloads */
	MateriaLightning&	operator=(const MateriaLightning&);
};

#endif