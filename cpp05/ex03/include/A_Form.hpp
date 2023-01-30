#ifndef A_FORM
#define A_FORM

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class A_Form
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
	class NonSignedForm : public FormException
	{
		public :
		const char* what( void ) const throw() { return ("[Exception] Form is unsigned"); }
	};

	/* Constructors */
	A_Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	A_Form(const A_Form&);
	virtual ~A_Form();

	/* Overloads */
	A_Form&	operator=(const A_Form&);

	/* Methods */
	void			checkGrade(int grade);
	void			beSigned( Bureaucrat& );
	void			beExecuted(Bureaucrat const & executor) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

	/* Accessors */
	std::string	getName( void ) const;
	bool		isSigned( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExecute( void ) const;


	protected :

	/* Constructors */
	A_Form();

	/* Attributes */
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

std::ostream&	operator<<(std::ostream &flow, A_Form const &value);

#endif