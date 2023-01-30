#ifndef INTERN
#define INTERN

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public :

	/* Constructors */
	Intern();
	Intern(const Intern&);
	~Intern();

	/* Overloads */
	Intern&	operator=(const Intern&);

	/* Methods */
	A_Form*	makeShrubberyCreationForm(std::string targetForm);
	A_Form*	makeRobotomyRequestForm(std::string targetForm);
	A_Form*	makePresidentialPardonForm(std::string targetForm);
	A_Form*	makeForm(std::string nameForm, std::string targetForm);


	private :

	/* Attributes */
	std::string	_formsLearned[3];
	A_Form*		(Intern::*_makeForms[3])(std::string);
	int			_countFormsLearned;
};

#endif