#ifndef A_FORM
#define A_FORM

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class A_Form
{
	public :

	class GradeTooHighException : public std::exception{
	};
	class GradeTooLowException : public std::exception{
	};

	/* Constructors */
	A_Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	A_Form(const A_Form&);
	virtual ~A_Form();

	/* Overloads */
	A_Form&	operator=(const A_Form&);

	/* Methods */
	void		beSigned( Bureaucrat& );

	/* Accessors */
	std::string	getName( void ) const;
	bool		isSigned( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExecute( void ) const;
	void		setGradeToSign(int grade) throw();
	void		setGradeToExecute(int grade) throw();


	protected :

	/* Constructors */
	A_Form();

	/* Attributes */
	const std::string	_name;
	bool				_signed;
	int					_gradeToSign;
	int					_gradeToExecute;
};

std::ostream&	operator<<(std::ostream &flow, A_Form const &value);

#endif