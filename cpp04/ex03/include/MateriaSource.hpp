#ifndef MATERIASOURCE
#define MATERIASOURCE

#include <iostream>

#include "I_MateriaSource.hpp"
#include "MateriaIce.hpp"
#include "MateriaCure.hpp"
#include "MateriaFire.hpp"
#include "MateriaLightning.hpp"

class MateriaSource : public I_MateriaSource
{
	public :

	/* Constructors */
	MateriaSource();
	MateriaSource(const MateriaSource&);
	~MateriaSource();

	/* Overloads */
	MateriaSource&	operator=(const MateriaSource&);

	/* Methods */
	void		learnMateria(A_Materia*);
	A_Materia*	createMateria(std::string const & type);


	/* Accessors */
	

	private :

	/* Attributes */
	A_Materia	*_inventory[4];
	int			_countMaterias;

};

#endif