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

	/* Overloads */

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	/* Accessors */
	

	private :

	/* Overloads */
	MateriaLightning&	operator=(const MateriaLightning&);

	/* Methods */
	MateriaLightning(const MateriaLightning&);
	
	/* Attributes */

};

#endif