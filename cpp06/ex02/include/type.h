#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <cstdlib>

#include "ABC.hpp"

/* type.cpp */
Base*	generate( void );
void	identify(Base* p);
void	identify(Base& p);

/* main.cpp */
int	main( void );

#endif