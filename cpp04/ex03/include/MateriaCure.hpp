#ifndef MATERIACURE
#define MATERIACURE

#include <iostream>

#include "A_Materia.hpp"

class MateriaCure : public A_Materia
{
	public :

	/* Constructors */
	MateriaCure();
	MateriaCure(const MateriaCure&);
	~MateriaCure();

	/* Overloads */
	MateriaCure&	operator=(const MateriaCure&);

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	/* Accessors */
	

	private :

	/* Attributes */
	

};

#endif