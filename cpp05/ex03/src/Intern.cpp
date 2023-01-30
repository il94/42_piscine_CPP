#include "../include/Intern.hpp"

/*=============================== Constructors ===============================*/

Intern::Intern(){
	std::cout << "[Intern] Default constructor called." << std::endl;

	_formsLearned[0] = "shrubbery creation";
	_formsLearned[1] = "robotomy request";
	_formsLearned[2] = "presidential pardon";

	_makeForms[0] = &Intern::makeShrubberyCreationForm;
	_makeForms[1] = &Intern::makeRobotomyRequestForm;
	_makeForms[2] = &Intern::makePresidentialPardonForm;

	_countFormsLearned = (sizeof(_formsLearned) / sizeof(std::string));
}

Intern::Intern(const Intern &src){
	std::cout << "[Intern] Copy constructor called." << std::endl;
	*this = src;
}

Intern::~Intern(){
	std::cout << "[Intern] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

Intern& Intern::operator=(const Intern &src)
{
	_countFormsLearned = src._countFormsLearned;
	for (int i = 0; i < _countFormsLearned; i++)
	{
		_formsLearned[i] = src._formsLearned[i];
		_makeForms[i] = src._makeForms[i];
	}
	return (*this);
}

/*================================= Methods ==================================*/

A_Form*	Intern::makePresidentialPardonForm(std::string targetForm){
	return (new PresidentialPardonForm(targetForm));
}

A_Form*	Intern::makeRobotomyRequestForm(std::string targetForm){
	return (new RobotomyRequestForm(targetForm));
}

A_Form*	Intern::makeShrubberyCreationForm(std::string targetForm){
	return (new ShrubberyCreationForm(targetForm));
}

A_Form*	Intern::makeForm(std::string nameForm, std::string targetForm)
{
	for (int i = 0; i < _countFormsLearned; i++)
	{
		if (nameForm == _formsLearned[i])
		{
			std::cout << "Intern creates " << nameForm << "." << std::endl;
			return ((this->*_makeForms[i])(targetForm));
		}
	}
	std::cout << "Intern creates RIEN DU TOUT ! Get out of my sight and never come back !" << std::endl;
	return (NULL);
}