#include "../include/Form.hpp"

/*=============================== Constructors ===============================*/

Form::Form() : _name("unamed"), _signed(false){
	std::cout << "[Form] Default constructor called." << std::endl;
	setGradeToSign(150);
	setGradeToExecute(150);
	std::cout << *this << " was created." << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _signed(false){
	std::cout << "[Form] Parameters constructor called." << std::endl;
	setGradeToSign(gradeToSign);
	setGradeToExecute(gradeToExecute);
	std::cout << *this << " was created." << std::endl;
}

Form::Form(const Form &src) : _name(src._name){
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
	_gradeToSign = src._gradeToSign;
	_gradeToExecute = src._gradeToExecute;
	return (*this);
}

/*================================= Methods ==================================*/

void	Form::beSigned(Bureaucrat& member) throw()
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

void	Form::setGradeToSign(int grade) throw()
{
	try
	{
		if (grade < 1)
			throw (GradeTooHighException());
		else if (grade > 150)
			throw (GradeTooLowException());
		else
			_gradeToSign = grade;
	}
	catch (GradeTooHighException&)
	{
		std::cout << grade << " is too high a grade" << std::endl;
		_gradeToSign = 1;
	}
	catch (GradeTooLowException&)
	{
		std::cout << grade << " is too low a grade" << std::endl;
		_gradeToSign = 150;
	}
}

void	Form::setGradeToExecute(int grade) throw()
{
	try
	{
		if (grade < 1)
			throw (GradeTooHighException());
		else if (grade > 150)
			throw (GradeTooLowException());
		else
			_gradeToExecute = grade;
	}
	catch (GradeTooHighException&)
	{
		std::cout << grade << " is too high a grade" << std::endl;
		_gradeToExecute = 1;
	}
	catch (GradeTooLowException&)
	{
		std::cout << grade << " is too low a grade" << std::endl;
		_gradeToExecute = 150;
	}
}

std::ostream&	operator<<(std::ostream &flow, Form const &value)
{
	flow << value.getName() << " | to sign : " << value.getGradeToSign();
	flow << " | to execute : " << value.getGradeToExecute();
	return (flow);
}