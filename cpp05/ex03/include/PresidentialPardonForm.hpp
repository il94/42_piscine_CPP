#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include <iostream>

#include "A_Form.hpp"

class PresidentialPardonForm : public A_Form
{
	public :

	/* Constructors */
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();

	/* Overloads */
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

	/* Methods */
	void	execute(Bureaucrat const & executor) const;


	private :

	/* Constructors */
	PresidentialPardonForm();

	/* Attributes */
	std::string	_target;

};

#endif