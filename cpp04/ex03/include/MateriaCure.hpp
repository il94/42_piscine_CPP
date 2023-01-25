#ifndef MATERIACURE
#define MATERIACURE

#include <iostream>

#include "A_Materia.hpp"
#include "I_Character.hpp"

class MateriaCure : public A_Materia
{
	public :

	/* Constructors */
	MateriaCure();
	~MateriaCure();

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	private :

	/* Constructors */
	MateriaCure(const MateriaCure&);

	/* Overloads */
	MateriaCure&	operator=(const MateriaCure&);
};

#endif