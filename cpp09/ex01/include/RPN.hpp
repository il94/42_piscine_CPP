#ifndef _RPN
#define _RPN

#include <iostream>
#include <cstring>

#include <string>
#include <stack>
#include <queue>
#include <algorithm>

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define END "\033[0m"

void	exitMessage(const std::string &message);

class RPN
{
	public :

	/* Constructors */
	RPN(const std::string &src);
	RPN(const RPN&);
	~RPN();

	/* Overloads */
	RPN&	operator=(const RPN&);

	/* Methods */
	long long	resolve( void );

	/* Accessors */
	long long	getResult( void ) const;
	void		setResult( const long long &src );

	private :

	/* Constructors */
	RPN();

	/* Methods */
	void	checkSyntax(const int &countValues, const int &countOperators, const char &lastElement) const;
	void	checkSyntax(const int &countValues, const int &countOperators) const;
	bool	isValidChar(const std::string &VALID_SET, char c) const;
	bool	isDigitUpper10(std::string &parameter, int i) const;

	/* Attributes */
	std::string			_equation;
	long long			_result;
};

#endif