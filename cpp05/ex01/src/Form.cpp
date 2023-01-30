#include "../include/Form.hpp"

/*=============================== Constructors ===============================*/

Form::Form() : _name("unamed"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
	std::cout << "[Form] Default constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	std::cout << "[Form] Parameters constructor called." << std::endl;
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
	std::cout << *this << " was created." << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute){
	std::cout << "[Form] Copy constructor called." << std::endl;
	*this = src;
	std::cout << *this << " was copied." << std::endl;
}

Form::~Form(){
	std::cout << "[Form] Default destructor called." << std::endl;
	std::cout << *this << " was destroyed." << std::endl;
}

/*================================ Overloads =================================*/

Form& Form::operator=(const Form &src)
{
	_signed = src._signed;
	return (*this);
}

/*================================= Methods ==================================*/

void	Form::checkGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

void	Form::beSigned(Bureaucrat& member)
{
	if (member.getGrade() <= getGradeToSign())
		_signed = true;
	else
		throw (GradeTooLowException());
}

/*================================ Accessors =================================*/

std::string	Form::getName( void ) const{
	return (_name);
}

bool	Form::isSigned( void ) const{
	return (_signed);
}

int	Form::getGradeToSign( void ) const{
	return (_gradeToSign);
}

int	Form::getGradeToExecute( void ) const{
	return (_gradeToExecute);
}


std::ostream&	operator<<(std::ostream &flow, Form const &value)
{
	flow << value.getName() << " | to sign : " << value.getGradeToSign();
	flow << " | to execute : " << value.getGradeToExecute();
	return (flow);
}