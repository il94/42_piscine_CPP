#ifndef LITTERAL
#define LITTERAL

#include "conversion.h"

class Litteral
{
	public :

	/* Constructors */
	Litteral(const char*);
	Litteral(const Litteral&);
	~Litteral();

	/* Overloads */
	Litteral&	operator=(const Litteral&);

	/* Methods */

	bool	isChar( void );
	bool	isInt( void );
	bool	isFloat( void );
	bool	isDouble( void );

	void	printChar( void );	
	void	printInt( void );	
	void	printFloat( void );	
	void	printDouble( void );	

	void	printValues( void );	
	

	private :

	/* Constructors */
	Litteral();

	/* Attributes */
	std::string	_string;
	long double	_value;
	type		_valueType;
	bool		_infValue;
	char		_char;
	int			_int;
	float		_float;
	double		_double;
};

#endif