#ifndef I_MATERIASOURCE
#define I_MATERIASOURCE

#include <iostream>
#include "A_Materia.hpp"

class I_MateriaSource
{
	public :

	/* Constructors */
	virtual	~I_MateriaSource();

	/* Overloads */

	/* Methods */
	virtual void		learnMateria(A_Materia*) = 0;
	virtual A_Materia*	createMateria(std::string const & type) = 0;
	

	/* Accessors */
	

	private :

	/* Attributes */
	

};

#endif