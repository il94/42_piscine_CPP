#ifndef FORM
#define FORM

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :

	class GradeTooHighException : public std::exception{
	};
	class GradeTooLowException : public std::exception{
	};

	/* Constructors */
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form&);
	~Form();

	/* Overloads */
	Form&	operator=(const Form&);

	/* Methods */
	void		beSigned( Bureaucrat& ) throw();

	/* Accessors */
	std::string	getName( void ) const;
	bool		isSigned( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExecute( void ) const;
	void		setGradeToSign(int grade) throw();
	void		setGradeToExecute(int grade) throw();


	private :

	/* Constructors */
	Form();

	/* Attributes */
	const std::string	_name;
	bool				_signed;
	int					_gradeToSign;
	int					_gradeToExecute;
};

std::ostream&	operator<<(std::ostream &flow, Form const &value);

#endif