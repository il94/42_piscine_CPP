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
	long long	result = 0;
	// int			tmp;

	result = _values.top();
	_values.pop();

	while (not _values.empty())
	{
		std::cout << "RES " << result << std::endl;
		std::cout << "VAL " << _values.top() << std::endl;
		std::cout << "OP "<< _operators.top() << std::endl;
		std::cout << "=================" << std::endl << std::endl;


		switch (_operators.top())
		{
			case '+' :
				result += _values.top();
				break ;
			case '-' :
				result -= _values.top();
				break ;
			case '*' :
				result *= _values.top();
				break ;
			case '/' :
				result /= _values.top();
				break ;
			default :
				std::cout << "RAYANES" << std::endl;
		}
		_operators.pop();
		_values.pop();
	}
	
	// std::cout << "_values.top()" << std::endl;

	// tmp = _values.top();
	// _values.pop();
	// result = 


	_result = result;
	return (getResult());
}

/*================================ Accessors =================================*/

long long	RPN::getResult( void ){
	return (_result);
}

