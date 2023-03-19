#include "../include/RPN.hpp"

RPN	parsingArgument(std::string parameter)
{
	RPN					result;
	const std::string	VALID_CHAR = "0123456789 +-*/";

	for (size_t i = 0; i < parameter.size(); i++)
	{
		if (std::find(VALID_CHAR.begin(), VALID_CHAR.end(), parameter[i]) == VALID_CHAR.end())
		{
			std::cout << "Caracter invalid" << std::endl;
			exit (1);
		}
		else if (std::isdigit(parameter[i]) and std::isdigit(parameter[i + 1]))
		{
			std::cout << "Values must be between 0 and 9" << std::endl;
			exit (1);
		}
		else if (parameter[i] != ' ')
			result.pushElement(parameter[i]);
	}
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 2 or not av[1][0])
	{
		std::cout << "Need only a polish mathematical expression in argument" << std::endl;
		return (1);
	}

	RPN			target = parsingArgument(av[1]);
	std::cout << target.applyRPN() << std::endl;


	return (0);
}