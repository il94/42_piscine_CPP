#include "../include/BitcoinExchange.hpp"

bool	isInt(const char* str)
{
    char	*endPtr;
	long	result = strtol(str, &endPtr, 10);

	// if (*str != '\0' and *endPtr == '\0'
	// 	and (result >= INT32_MIN and result <= INT32_MAX))
	// 	std::cout << RED << "Is int" << END << std::endl;
	// else
	// 	std::cout << RED << "Not int" << END << std::endl;

    return (*str != '\0' and *endPtr == '\0'
		and (result >= INT32_MIN and result <= INT32_MAX));
}

bool	isFloat(const char* str)
{
	char*	endPtr;
	double	result = strtod(str, &endPtr);

	// if (*str != '\0' and *endPtr == '\0'
	// 	and (result >= INT32_MIN and result <= INT32_MAX))
	// 	std::cout << RED << "Is int" << END << std::endl;
	// else
	// 	std::cout << RED << "Not int" << END << std::endl;

    return (*str != '\0' and *endPtr == '\0'
		and (result >= INT32_MIN and result <= INT32_MAX));
}

/*===================================================================*/

void	exitMessage(const std::string &message)
{
	std::cerr << message << std::endl;
	exit (EXIT_FAILURE);
}

void	isValidInput(const int &numberParameters, const char *fileName)
{
	if (numberParameters != 1)
	{
		if (numberParameters < 1)
			exitMessage("[ERROR] Need an argument");
		else
			exitMessage("[ERROR] Too many arguments");
	}
}

int	main(int ac, char **av)
{
	try
	{
		BitcoinExchange	BTC("data.csv");

		isValidInput(ac - 1, *(av + 1));
		BTC.fill(*(av + 1));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}