#ifndef A_MATERIA
#define A_MATERIA

#include <iostream>

class A_Materia
{
	public :

	/* Constructors */
	A_Materia();
	A_Materia(std::string const &type);
	~A_Materia();

	/* Overloads */
	A_Materia&	operator=(const A_Materia&);

	/* Methods */
	virtual A_Materia*	clone( void ) const = 0;
	virtual	void		use(I_Character& target);

	/* Accessors */
	std::string const&	getType( void ) const;

	protected :

	/* Constructors */
	A_Materia(const A_Materia&);

	/* Attributes */
	std::string	_type;
};

#endif