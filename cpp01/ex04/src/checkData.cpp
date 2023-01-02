#include "../include/replace.h"

bool	isValidInput(int nbParameters, char *s1)
{
	if (nbParameters != 3)
	{
		std::cout << "Invalid number of arguments\n";
		return (false);
	}
	if (!s1[0])
	{
		std::cout << "Invalid S1\n";
		return (false);
	}
	return (true);
}
