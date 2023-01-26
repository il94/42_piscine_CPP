#include "../include/Bureaucrat.hpp"

/*=============================== Constructors ===============================*/

Bureaucrat::Bureaucrat() : _name("unamed"){
	std::cout << "[Bureaucrat] Default constructor called." << std::endl;
	setGrade(150);
	std::cout << getName() << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name){
	std::cout << "[Bureaucrat] Parameters constructor called." << std::endl;
	setGrade(grade);
	std::cout << *this << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src){
	std::cout << "[Bureaucrat] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getName() << " was copied." << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "[Bureaucrat] Default destructor called." << std::endl;
	std::cout << getName() << " was destroyed." << std::endl;
}

/*================================ Overloads =================================*/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src._grade;
	return (*this);
}

/*================================= Methods ==================================*/

void Bureaucrat::upgrade( void ){
	setGrade(_grade - 1);
}

void Bureaucrat::downgrade( void ){
	setGrade(_grade + 1);
}

/*================================ Accessors =================================*/

std::string	Bureaucrat::getName( void ) const{
	return (_name);
}

int	Bureaucrat::getGrade( void ) const{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade < 1)
			throw (GradeTooHighException());
		else if (grade > 150)
			throw (GradeTooLowException());
		else
			_grade = grade;
	}
	catch (GradeTooHighException&)
	{
		std::cout << grade << " is too high for a grade" << std::endl;
		_grade = 1;
	}
	catch (GradeTooLowException&)
	{
		std::cout << grade << " is too low for a grade" << std::endl;
		_grade = 150;
	}
}

std::ostream&	operator<<(std::ostream &flow, Bureaucrat const &value)
{
	flow << value.getName() << ", bureaucrat grade " << value.getGrade();
	return (flow);
}