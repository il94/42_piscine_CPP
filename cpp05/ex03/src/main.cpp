#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int	main( void )
{
	Bureaucrat	nouveau("Célestin", 150);
	Bureaucrat	manager("Titouanville", 75);
	Bureaucrat	boss("M.Landolsi", 1);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	Intern		slave;
	std::cout << std::endl;

	A_Form*	trees = slave.makeForm("shrubbery creation", "Tree");
	std::cout << std::endl;

	A_Form*	robot = slave.makeForm("robotomy request", "Dimitri");
	std::cout << std::endl;

	A_Form*	zaphod = slave.makeForm("presidential pardon", "Titouan");
	std::cout << std::endl;

	A_Form*	fail = slave.makeForm("ytb tutorial get summer body in 3 days without sport", "lol");
	(void)fail;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;
	
	nouveau.executeForm(*zaphod);
	boss.signForm(*zaphod);
	nouveau.executeForm(*zaphod);
	std::cout << std::endl;

	boss.signForm(*trees);
	manager.executeForm(*trees);
	std::cout << std::endl;

	boss.signForm(*robot);
	boss.executeForm(*robot);
	boss.executeForm(*robot);
	std::cout << std::endl;

	boss.signForm(*zaphod);
	boss.executeForm(*zaphod);
	std::cout << std::endl;

	delete trees;
	delete robot;
	delete zaphod;

	return (0);
}