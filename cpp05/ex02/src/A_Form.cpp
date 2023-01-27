#include "../include/A_Form.hpp"

/*=============================== Constructors ===============================*/

A_Form::A_Form() : _name("unamed"), _signed(false){
	std::cout << "[A_Form] Default constructor called." << std::endl;
	setGradeToSign(150);
	setGradeToExecute(150);
	std::cout << *this << " was created." << std::endl;
}

A_Form::A_Form(const std::string name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _signed(false){
	std::cout << "[A_Form] Parameters constructor called." << std::endl;
	setGradeToSign(gradeToSign);
	setGradeToExecute(gradeToExecute);
	std::cout << *this << " was created." << std::endl;
}

A_Form::A_Form(const A_Form &src) : _name(src._name){
	std::cout << "[A_Form] Copy constructor called." << std::endl;
	*this = src;
	std::cout << *this << " was copied." << std::endl;
}

A_Form::~A_Form(){
	std::cout << "[A_Form] Default destructor called." << std::endl;
	std::cout << *this << " was destroyed." << std::endl;
}

/*================================ Overloads =================================*/

A_Form& A_Form::operator=(const A_Form &src)
{
	_signed = src._signed;
	_gradeToSign = src._gradeToSign;
	_gradeToExecute = src._gradeToExecute;
	return (*this);
}

/*================================= Methods ==================================*/

void	A_Form::beSigned(Bureaucrat& member)
{
	if (member.getGrade() <= getGradeToSign())
		_signed = true;
	else
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

void	A_Form::setGradeToSign(int grade) throw()
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

void	A_Form::setGradeToExecute(int grade) throw()
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

std::ostream&	operator<<(std::ostream &flow, A_Form const &value)
{
	flow << value.getName() << " | to sign : " << value.getGradeToSign();
	flow << " | to execute : " << value.getGradeToExecute();
	return (flow);
}