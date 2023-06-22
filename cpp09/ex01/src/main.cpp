#include "../include/RPN.hpp"

void	exitMessage(const std::string &message)
{
	std::cerr << message << std::endl;
	exit (EXIT_FAILURE);
}

void	isValidInput(const int &numberParameters)
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
	isValidInput(ac - 1);

	RPN	Rpn(av[1]);
	std::cout << Rpn.applyRPN() << std::endl;

	return (0);
}