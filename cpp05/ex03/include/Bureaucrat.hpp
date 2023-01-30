#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>

#include "A_Form.hpp"

class A_Form;

class Bureaucrat
{
	public :

	class BureaucratException : public std::exception
	{
		public :
		virtual const char* what( void ) const throw() = 0;
	};
	class GradeTooHighException : public BureaucratException
	{
		public :
		virtual const char* what( void ) const throw() { return ("[Exception] Grade too high"); }
	};
	class GradeTooLowException : public BureaucratException
	{
		public :
		virtual const char* what( void ) const throw() { return ("[Exception] Grade too low"); }
	};

	/* Constructors */
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();

	/* Overloads */
	Bureaucrat&	operator=(const Bureaucrat&);

	/* Methods */
	void		upgrade( void );
	void		downgrade( void );
	void		checkGrade(int grade);
	void		signForm( A_Form& );
	void		executeForm(A_Form const&);

	/* Accessors */
	std::string	getName( void ) const;
	int			getGrade( void ) const;


	private :

	/* Constructors */
	Bureaucrat();

	/* Attributes */
	const std::string	_name;
	int					_grade;

};

std::ostream&	operator<<(std::ostream &flow, Bureaucrat const &value);

#endif