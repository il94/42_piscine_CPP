#ifndef FORM
#define FORM

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :

	class FormException : public std::exception
	{
		public :
		virtual const char* what( void ) const throw() = 0;
	};

	class GradeTooHighException : public FormException
	{
		public :
		const char* what( void ) const throw() { return ("[Exception] Grade too high"); }
	};
	class GradeTooLowException : public FormException
	{
		public :
		const char* what( void ) const throw() { return ("[Exception] Grade too low"); }
	};

	/* Constructors */
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form&);
	~Form();

	/* Overloads */
	Form&	operator=(const Form&);

	/* Methods */
	void		checkGrade(int grade);
	void		beSigned( Bureaucrat& );

	/* Accessors */
	std::string	getName( void ) const;
	bool		isSigned( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExecute( void ) const;


	private :

	/* Constructors */
	Form();

	/* Attributes */
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

std::ostream&	operator<<(std::ostream &flow, Form const &value);

#endif