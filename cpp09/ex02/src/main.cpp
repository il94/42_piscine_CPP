#include "../include/PmergeMe.hpp"

bool	isInt(const char* str)
{
    char	*endPtr;
	long	result = strtol(str, &endPtr, 10);

    return (*str != '\0' and *endPtr == '\0'
		and (result >= INT_MIN and result <= INT_MAX));
}

void	exitMessage(const std::string &message)
{
	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	std::cerr << message << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	exit (EXIT_FAILURE);
}

void	isValidInput(const int &numberParameters)
{
	if (numberParameters < 1)
		exitMessage("[ERROR] Need an argument");
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exitMessage("[ERROR] Need an argument");

	PmergeMe	pmergeMe;

	size_t		i = 1;
	int			count[ac - 1];

	while (av[i])
	{
		if (not isInt(av[i]))
			exitMessage("[ERROR] \"" + std::string(av[i]) + "\" is not an integer");
		pmergeMe.push(std::atoi(av[i]));
		i++;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	// pmergeMe.displayTemp();

	pmergeMe.sort();
	
	// pmergeMe.display();



	// std::cout << std::endl;
	// std::cout << "===================================" << std::endl;
	// std::cout << std::endl;

	// pmergeMe.displayResult();

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	return (0);
}