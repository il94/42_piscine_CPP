#include "../include/PresidentialPardonForm.hpp"

/*=============================== Constructors ===============================*/

PresidentialPardonForm::PresidentialPardonForm() : A_Form(), _target("unamed"){
	std::cout << "[PresidentialPardonForm] Default constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	A_Form("PresidentialPardon", 25, 5), _target(target) {
	std::cout << "[PresidentialPardonForm] Parameters constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	A_Form(src){
	std::cout << "[PresidentialPardonForm] Copy constructor called." << std::endl;
	*this = src;
	std::cout << *this << " was copied." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "[PresidentialPardonForm] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	_signed = src._signed;
	_target = src._target;
	return (*this);
}

/*================================= Methods ==================================*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	beExecuted(executor);
	std::cout << _target << " was forgiven by Zaphod Beeblebrox." << std::endl;
}