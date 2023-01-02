#include "../include/replace.h"

int main(int ac, char **av)
{
	if (!isValidInput(ac - 1, av[2]))
		exit (EXIT_FAILURE);
	run(av[1], av[2], av[3]);
	return (0);
}