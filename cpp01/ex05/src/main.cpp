#include "../include/Harl.hpp"

int	main()
{
	Harl	harl;

	std::cout << "Harl raconte sa vie [DEBUG]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Harl est un radin [INFO]" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "Harl manque de respect [WARNING]" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "Harl devienne fou [ERROR]" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "Harl n'est jamais content [LEVEL INVALID]" << std::endl;
	harl.complain("LEVEL INVALID");
	return (0);
}