#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>

class Bureaucrat
{
	public :

	class GradeTooHighException : public std::exception{
	};
	class GradeTooLowException : public std::exception{
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

	/* Accessors */
	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		setGrade(int grade) throw();


	private :

	/* Constructors */
	Bureaucrat();

	/* Attributes */
	const std::string	_name;
	int					_grade;

};

std::ostream&	operator<<(std::ostream &flow, Bureaucrat const &value);

#endif