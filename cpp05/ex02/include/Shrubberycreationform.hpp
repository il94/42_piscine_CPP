#ifndef ShrubberyCreationForm
#define ShrubberyCreationForm

#include <iostream>

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
	

	/* Accessors */
	

	private :

	/* Constructors */
	ShrubberyCreationForm();

	/* Attributes */
	std::string	_target;

};

#endif