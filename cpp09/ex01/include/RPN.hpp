#ifndef _RPN
#define _RPN

#include <iostream>
#include <cstring>

#include <string>
#include <stack>
#include <algorithm>

class RPN
{
	public :

	/* Constructors */
	RPN();
	RPN(const RPN&);
	~RPN();

	/* Overloads */
	RPN&	operator=(const RPN&);

	/* Methods */
	long long	applyRPN( void );

	template < typename T >
	void	pushElement(T element)
	{
		if (std::isdigit(element))
			_values.push(element - 48);
		else
			_operators.push(element);
	}

	template < typename T >
	void	popElement(T element)
	{
		if (std::isdigit(element))
			_values.pop();
		else
			_operators.pop();
	}

	/* Accessors */
	long long	getResult( void );

	private :

	/* Attributes */
	// const std::string	_charOperators = "+-*/"

	std::stack<int>		_values;
	std::stack<char>	_operators;
	long long			_result;


};

#endif