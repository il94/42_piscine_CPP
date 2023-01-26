#include "../include/Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat	nouveau("Célestin", 151);
	std::cout << std::endl;

	Bureaucrat	manager("Titouanville", 100);
	std::cout << std::endl;

	Bureaucrat	boss("M.Landolsi", -1);
	std::cout << std::endl;

	nouveau.downgrade();
	nouveau.upgrade();
	boss.upgrade();
	std::cout << std::endl;

	return (0);
}