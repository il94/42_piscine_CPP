#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int	main( void )
{
	Bureaucrat	nouveau("Célestin", 150);
	Bureaucrat	manager("Titouanville", 75);
	Bureaucrat	boss("M.Landolsi", 1);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm	trees("Tree");
	std::cout << std::endl;

	RobotomyRequestForm	robot("Dimitri");
	std::cout << std::endl;

	PresidentialPardonForm	zaphod("Brigabroug");

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;
	
	nouveau.executeForm(zaphod);
	boss.signForm(zaphod);
	nouveau.executeForm(zaphod);
	std::cout << std::endl;

	boss.signForm(trees);
	manager.executeForm(trees);
	std::cout << std::endl;

	boss.signForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	std::cout << std::endl;

	boss.signForm(zaphod);
	boss.executeForm(zaphod);
	std::cout << std::endl;

	return (0);
}