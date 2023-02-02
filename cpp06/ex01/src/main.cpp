#include "../include/serialisation.h"

int	main( void )
{
	uintptr_t	voiciUnPtr = 0;

	Data	voiciUneData;
	Data*	voiciUneNouvelleData = NULL;

	voiciUneData._string = "fifou la string des petits filous";
	voiciUneData._value = 43;

	printData(&voiciUneData, "Old");
	printData(voiciUneNouvelleData, "New");
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	voiciUnPtr = serialize(&voiciUneData);
	printData(&voiciUneData, "Old");
	printData(voiciUneNouvelleData, "New");
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	voiciUneNouvelleData = deserialize(voiciUnPtr);
	printData(&voiciUneData, "Old");
	printData(voiciUneNouvelleData, "New");
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;
	return (0);
}