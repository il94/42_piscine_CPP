#include "../include/RPN.hpp"

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

void	isValidInput(const int &numberParameters, char **parameters)
{
	if (numberParameters != 1)
	{
		if (numberParameters < 1)
			exitMessage("[ERROR] Need an argument");
		else
			exitMessage("[ERROR] Too many arguments");
	}
	if (parameters[1][0] == '\0')
		exitMessage("[ERROR] Need an argument");
}

int	main(int ac, char **av)
{
	isValidInput(ac - 1, av);

	RPN	Rpn(av[1]);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	long long	result = Rpn.resolve();
	std::cout << YELLOW << av[1] << END << " = " << GREEN << result << END << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	return (0);
}