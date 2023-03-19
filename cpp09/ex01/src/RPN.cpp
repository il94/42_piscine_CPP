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
	// long long	result = 0;
	// int			tmp;

	// tmp = _values.top();
	// _values.pop();
	// result = 


	// result = 
	return (getResult());
}

/*================================ Accessors =================================*/

long long	RPN::getResult( void ){
	return (_result);
}

