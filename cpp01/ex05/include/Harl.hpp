#ifndef HARL
#define HARL

#include <iostream>

class Harl
{
	public :
	
	Harl();

	void	complain(std::string level);

	private :

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

	void	(Harl::*_array[8])();
};

#endif