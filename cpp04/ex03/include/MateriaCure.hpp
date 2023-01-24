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

	/* Overloads */

	/* Methods */
	A_Materia*	clone( void ) const;
	void		use(I_Character& target);

	/* Accessors */
	

	private :

	/* Overloads */
	MateriaCure&	operator=(const MateriaCure&);

	/* Methods */
	MateriaCure(const MateriaCure&);
	
	/* Attributes */

};

#endif