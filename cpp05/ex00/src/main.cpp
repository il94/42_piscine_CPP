#include "../include/Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat	nouveau("Célestin", 151);
		std::cout << std::endl;
	}
	catch (Bureaucrat::BureaucratException& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	boss("M.Landolsi", -1);
		std::cout << std::endl;
	}
	catch (Bureaucrat::BureaucratException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	Bureaucrat	nouveau("Célestin", 150);
	Bureaucrat	manager("Titouanville", 75);
	Bureaucrat	boss("M.Landolsi", 1);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	nouveau.downgrade();
	nouveau.upgrade();
	boss.upgrade();

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	return (0);
}