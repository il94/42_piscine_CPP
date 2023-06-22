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
	// template < typename T >
	// void	pushElement(T element)
	// {
	// 	if (std::isdigit(element))
	// 		_values.push(element - 48);
	// 	else
	// 		_operators.push(element);
	// }

	// template < typename T >
	// void	pushElement2(T element)
	// {
	// 	if (std::isdigit(element))
	// 		_equation.push(element - 48);
	// 	else
	// 		_equation.push(element);
	// }

	// template < typename T >
	// void	popElement(T element)
	// {
	// 	if (std::isdigit(element))
	// 		_values.pop();
	// 	else
	// 		_operators.pop();
	// }

	long long	applyRPN( void );

	bool		isInvalidSyntax(const int &countValues, const int &countOperators, const char &lastElement);
	bool		isInvalidSyntax(const int &countValues, const int &countOperators);
	bool		isValidChar(const std::string &VALID_SET, char c);
	bool		isDigitUpper10(std::string &parameter, int i);
	bool		isOperator(char const c);

	/* Accessors */
	long long	getResult( void );
	int			getSizeValues( void );
	int			getSizeOperators( void );

	private :

	/* Constructors */
	RPN();

	/* Attributes */

	std::string			_equation;
	long long			_result;
};

#endif