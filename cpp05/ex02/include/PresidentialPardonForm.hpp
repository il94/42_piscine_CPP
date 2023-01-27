#ifndef PresidentialPardonForm
#define PresidentialPardonForm

#include <iostream>

#include "A_Form.hpp"

class PresidentialPardonForm : public A_Form
{
	public :

	/* Constructors */
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();

	/* Overloads */
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

	/* Methods */
	

	/* Accessors */
	

	private :

	/* Attributes */
	

};

#endif