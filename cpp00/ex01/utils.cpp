#include "phonebook.h"

void	printAndGetline(std::string to_print, std::string &input)
{
	std::cout << to_print;
	std::getline(std::cin, input);
}

int	convertInputToIndex(int index_max)
{
	std::string	input;

	while (input.size() != 1 || !isdigit(input[0])
		|| input[0] - '0' < 1 || input[0] - '0' > index_max)
		printAndGetline("\t\t Index : ", input);
	return (input[0] - '0' - 1);
}
