#include "../include/Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "What are these entries ? It's all nonsense !" << std::endl;
		return (1);
	}
	Harl	harl;
	harl.complain(av[1]);
	return (0);
}