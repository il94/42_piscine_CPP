#include "../include/serialisation.h"

void	printData(Data *src, std::string type)
{
	if (src)
	{
		std::cout << type << " Data" << " | string = " << src->_string;
		std::cout << " | value = " << src->_value << std::endl;
	}
	else
		std::cout << type << " Data" << " is NULL (mdr le nul)" << std::endl;
}

uintptr_t	serialize(Data* ptr)
{
	std::cout << "Data --to--> Uintptr" << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	std::cout << "Data <--to-- Uintptr" << std::endl;
	return (reinterpret_cast<Data *>(raw));
}
