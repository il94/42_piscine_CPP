#include "../include/RobotomyRequestForm.hpp"

/*=============================== Constructors ===============================*/

RobotomyRequestForm::RobotomyRequestForm() : A_Form(), _target("unamed"){
	std::cout << "[RobotomyRequestForm] Default constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	A_Form("RobotomyRequest", 72, 45), _target(target){
	std::cout << "[RobotomyRequestForm] Parameters constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	A_Form(src){
	std::cout << "[RobotomyRequestForm] Copy constructor called." << std::endl;
	*this = src;
	std::cout << *this << " was copied." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "[RobotomyRequestForm] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	_signed = src._signed;
	_target = src._target;
	return (*this);
}

/*================================= Methods ==================================*/

bool	RobotomyRequestForm::canBeRobotomized( void ) const{
	return (std::rand() % 2);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	beExecuted(executor);
	std::cout << "** BBBVVVVVVPPPPPPPRRRRTTTTTTTTTTT **" << std::endl;
	if (canBeRobotomized())
		std::cout << _target << " has been robotomised..." << std::endl;
	else
		std::cout << _target << " has resisted to the robotomisation !" << std::endl;
}