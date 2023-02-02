#include "../include/conversion.h"

bool    isValidInput(int nBParameters, char **parameters)
{
	if (nBParameters < 1)
	{
		std::cout << "ERROR : There is no parameter" << std::endl;
		return (false);
	}
	else if (nBParameters > 1)
	{
		std::cout << "ERROR : Too many parameters" << std::endl;
		return (false);
	}
	else if (not parameters[0][0])
	{
		std::cout << "ERROR : Parameter is empty" << std::endl;
		return (false);
	}
	return (true);
}