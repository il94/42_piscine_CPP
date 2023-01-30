#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main( void )
{
	Bureaucrat	nouveau("Célestin", 150);
	Bureaucrat	manager("Titouanville", 75);
	Bureaucrat	boss("M.Landolsi", 1);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	try
	{
		Form	cdi("CDI", -1, -1);
		std::cout << std::endl;
	}
	catch (Form::FormException& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	morceauDePapier("Morceau de papier", 100, 151);
		std::cout << std::endl;
	}
	catch (Form::FormException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	Form	cdi("CDI", 1, 1);
	Form	augmentation("Augmentation", 1, 1);
	Form	morceauDePapier("Morceau de papier", 100, 150);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;
	
	nouveau.signForm(augmentation);
	std::cout << std::endl;

	manager.signForm(morceauDePapier);
	std::cout << std::endl;

	manager.signForm(cdi);
	std::cout << std::endl;

	boss.signForm(cdi);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	return (0);
}