#include "../include/Bureaucrat.hpp"

/*=============================== Constructors ===============================*/

Bureaucrat::Bureaucrat() : _name("unamed"), _grade(150){
	std::cout << "[Bureaucrat] Default constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade){
	std::cout << "[Bureaucrat] Parameters constructor called." << std::endl;
	checkGrade(grade);
	std::cout << *this << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name){
	std::cout << "[Bureaucrat] Copy constructor called." << std::endl;
	*this = src;
	std::cout << *this << " was copied." << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "[Bureaucrat] Default destructor called." << std::endl;
	std::cout << *this << " was destroyed." << std::endl;
}

/*================================ Overloads =================================*/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src._grade;
	return (*this);
}

/*================================= Methods ==================================*/

void Bureaucrat::upgrade( void ){
	try
	{
		checkGrade(_grade - 1);
		_grade = _grade - 1;
		std::cout << getName() << " has been upgraded !" << std::endl;
	}
	catch (BureaucratException& e){
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::downgrade( void ){
	try
	{
		checkGrade(_grade + 1);
		_grade = _grade + 1;
		std::cout << getName() << " has been downgraded..." << std::endl;
	}
	catch (BureaucratException& e){
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

void	Bureaucrat::signForm(Form& document)
{
	try
	{
		document.beSigned(*this);
		std::cout << getName() << " signed " << document.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn't sign " << document.getName() << ", ";
		std::cout << "because he is too bad." << std::endl;
		std::cout << e.what() << std::endl;
	}
}

/*================================ Accessors =================================*/

std::string	Bureaucrat::getName( void ) const{
	return (_name);
}

int	Bureaucrat::getGrade( void ) const{
	return (_grade);
}

std::ostream&	operator<<(std::ostream &flow, Bureaucrat const &value)
{
	flow << value.getName() << ", bureaucrat grade " << value.getGrade();
	return (flow);
}