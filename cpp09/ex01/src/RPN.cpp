#include "../include/RPN.hpp"

/*=============================== Constructors ===============================*/

RPN::RPN(){
}

RPN::RPN(const RPN &src){
	*this = src;
}

RPN::~RPN(){
}

/*================================ Overloads =================================*/

RPN& RPN::operator=(const RPN &src)
{
	_values = src._values;
	_operators = src._operators;
	_result = src._result;
	return (*this);
}

/*================================= Methods ==================================*/

long long	RPN::applyRPN( void )
{
	long long	result;

	result = _values.top();
	_values.pop();

	while (not _values.empty())
	{
		switch (_operators.front())
		{
			case '+' :
				result += _values.top();
				break ;
			case '-' :
				result = _values.top() - result;
				break ;
			case '*' :
				result *= _values.top();
				break ;
			case '/' :
				if (result == 0)
				{
					std::cout << "Division by 0" << std::endl;
					exit (1);
				}
				result  = _values.top() / result;
				break ;
		}
		_operators.pop();
		_values.pop();
	}
	_result = result;
	return (getResult());
}

/*================================ Accessors =================================*/

long long	RPN::getResult( void ){
	return (_result);
}

int	RPN::getSizeValues( void ){
	return (_values.size());
}

int	RPN::getSizeOperators( void ){
	return (_operators.size());
}