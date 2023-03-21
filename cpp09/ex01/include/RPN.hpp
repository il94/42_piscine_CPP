#ifndef _RPN
#define _RPN

#include <iostream>
#include <cstring>

#include <string>
#include <stack>
#include <queue>
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

	long long	applyRPN( void );

	/* Accessors */
	long long	getResult( void );
	int			getSizeValues( void );
	int			getSizeOperators( void );

	private :

	/* Attributes */

	std::stack<int>		_values;
	std::queue<char>	_operators;
	long long			_result;
};

#endif