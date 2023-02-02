#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <cstdlib>

typedef enum type{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	type;

#include "Litteral.hpp"

/* utils.cpp */
bool    decimalIsZero( std::string& );

/* parsing.cpp */
bool    isValidInput(int nBParameters, char **parameters);

/* main.cpp */
int	main(int ac, char **av);

#endif