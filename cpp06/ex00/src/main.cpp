#include "../include/conversion.h"

int	main(int ac, char **av)
{
	if (not isValidInput(ac - 1, av + 1))
		return (1);

	Litteral	value(av[1]);

	value.printValues();

	return (0);
}