#include "../include/RPN.hpp"

bool	isValidChar(const std::string &VALID_SET, char c){
	return (std::find(VALID_SET.begin(), VALID_SET.end(), c) != VALID_SET.end());
}

bool	isDigitUpper10(std::string &parameter, int i){
	return (std::isdigit(parameter[i]) and std::isdigit(parameter[i + 1]));
}

bool	isInvalidSyntax(RPN &result){
	return (result.getSizeValues() == 1 and result.getSizeOperators() == 1);
}

bool	countElementIsInvalid(RPN &result)
{
	if (result.getSizeValues() <= result.getSizeOperators())
	{
		std::cout << "To many operators" << std::endl;
		return (1);
	}
	else if (result.getSizeValues() > result.getSizeOperators() + 1)
	{
		std::cout << "To many values" << std::endl;
		return (1);
	}
	return (0);
}

RPN	parsingArgument(std::string parameter)
{
	RPN					result;
	const std::string	VALID_SET = "0123456789 +-*/";
	char				lastElement;

	for (size_t i = 0; i < parameter.size(); i++)
	{
		if (not isValidChar(VALID_SET, parameter[i]))
		{
			std::cout << "Caracter invalid" << std::endl;
			exit (1);
		}
		else if (isDigitUpper10(parameter, i))
		{
			std::cout << "Values must be between 0 and 9" << std::endl;
			exit (1);
		}
		else if (parameter[i] != ' ')
		{
			result.pushElement(parameter[i]);
			lastElement = parameter[i];
		}
		if (isInvalidSyntax(result))
		{
			std::cout << "Invalid syntax" << std::endl;
			exit (1);
		}
	}
	if (std::isdigit(lastElement))
	{
		std::cout << "Invalid syntax" << std::endl;
		exit (1);
	}
	if (countElementIsInvalid(result))
		exit (1);
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