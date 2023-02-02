#ifndef SERIALISATION_H
#define SERIALISATION_H

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string	_string;
	int			_value;
};

/* main.cpp*/
void		printData(Data *src, std::string type);
uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

/* main.cpp*/
int	main( void );

#endif