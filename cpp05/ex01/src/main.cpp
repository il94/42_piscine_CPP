#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main( void )
{
	Bureaucrat	nouveau("Célestin", 150);
	std::cout << std::endl;

	Bureaucrat	manager("Titouanville", 75);
	std::cout << std::endl;

	Bureaucrat	boss("M.Landolsi", 1);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	Form	cdi("CDI", -1, -1);
	std::cout << std::endl;

	Form	augmentation("Augmentation", 1, 1);
	std::cout << std::endl;

	Form	morceauDePapier("Morceau de papier", 100, 151);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;
	

	nouveau.signForm(augmentation);
	std::cout << std::endl;

	manager.signForm(morceauDePapier);
	std::cout << std::endl;

	return (0);
}