#include "../include/A_Form.hpp"

/*=============================== Constructors ===============================*/

A_Form::A_Form() : _name("unamed"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
	std::cout << "[A_Form] Default constructor called." << std::endl;
}

A_Form::A_Form(const std::string name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	std::cout << "[A_Form] Parameters constructor called." << std::endl;
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

A_Form::A_Form(const A_Form &src) : _name(src._name), _gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute){
	std::cout << "[A_Form] Copy constructor called." << std::endl;
	*this = src;
}

A_Form::~A_Form(){
	std::cout << "[A_Form] Default destructor called." << std::endl;
	std::cout << *this << " was destroyed." << std::endl;
}

/*================================ Overloads =================================*/

A_Form& A_Form::operator=(const A_Form &src)
{
	_signed = src._signed;
	return (*this);
}

/*================================= Methods ==================================*/

void	A_Form::checkGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

void	A_Form::beSigned(Bureaucrat& member)
{
	if (member.getGrade() <= getGradeToSign())
		_signed = true;
	else
		throw (GradeTooLowException());
}

void	A_Form::beExecuted(Bureaucrat const & executor) const
{
	if (not isSigned())
		throw (NonSignedForm());
	else if (executor.getGrade() > getGradeToExecute())
		throw (GradeTooLowException());
}

/*================================ Accessors =================================*/

std::string	A_Form::getName( void ) const{
	return (_name);
}

bool	A_Form::isSigned( void ) const{
	return (_signed);
}

int	A_Form::getGradeToSign( void ) const{
	return (_gradeToSign);
}

int	A_Form::getGradeToExecute( void ) const{
	return (_gradeToExecute);
}


std::ostream&	operator<<(std::ostream &flow, A_Form const &value)
{
	flow << value.getName() << " | to sign : " << value.getGradeToSign();
	flow << " | to execute : " << value.getGradeToExecute();
	return (flow);
}