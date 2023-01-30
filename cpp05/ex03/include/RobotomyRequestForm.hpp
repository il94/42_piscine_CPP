#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include <iostream>
#include <cstdlib>

#include "A_Form.hpp"

class RobotomyRequestForm : public A_Form
{
	public :

	/* Constructors */
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm&);
	~RobotomyRequestForm();

	/* Overloads */
	RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

	/* Methods */
	bool	canBeRobotomized( void ) const ;
	void	execute(Bureaucrat const & executor) const;


	private :

	/* Constructors */
	RobotomyRequestForm();

	/* Attributes */
	std::string	_target;
};

#endif