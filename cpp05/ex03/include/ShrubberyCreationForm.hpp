#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include <iostream>
#include <fstream>

#include "A_Form.hpp"

class ShrubberyCreationForm : public A_Form
{
	public :

	/* Constructors */
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();

	/* Overloads */
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);

	/* Methods */
	void	execute(Bureaucrat const & executor) const;


	private :

	/* Constructors */
	ShrubberyCreationForm();

	/* Attributes */
	std::string	_target;

};

#endif