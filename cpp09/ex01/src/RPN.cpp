#include "../include/RPN.hpp"

/*=============================== Constructors ===============================*/

RPN::RPN(){
	std::cout << "[RPN] Default constructor called." << std::endl;
}

RPN::RPN(const std::string &src) : _equation(src){
	std::cout << "[RPN] Parameters constructor called." << std::endl;

	char				lastElement;
	const std::string	VALID_SET = "0123456789 +-*/";
	size_t				countValues = 0;
	size_t				countOperators = 0;

	for (size_t i = 0; i < _equation.size(); i++)
	{
		if (not isValidChar(VALID_SET, _equation[i]))
		{
			std::cout << "Caracter invalid" << std::endl;
			exit (1);
		}
		else if (isDigitUpper10(_equation, i))
		{
			std::cout << "Values must be between 0 and 9" << std::endl;
			exit (1);
		}
		else if (_equation[i] != ' ')
		{
			if (std::isdigit(_equation[i]))
				countValues++;
			else
				countOperators++;
			lastElement = _equation[i];
		}
		if (isInvalidSyntax(countValues, countOperators))
		{
			std::cout << "Invalid syntax" << std::endl;
			exit (1);
		}
	}
	if (isInvalidSyntax(countValues, countOperators, lastElement))
		exit (1);
}

RPN::RPN(const RPN &src){
	std::cout << "[RPN] Copy constructor called." << std::endl;
	*this = src;
}

RPN::~RPN(){
	std::cout << "[RPN] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

RPN& RPN::operator=(const RPN &src)
{
	_equation = src._equation;
	// _values = src._values;
	// _operators = src._operators;
	// _result = src._result;
	return (*this);
}

/*================================= Methods ==================================*/


// bool	RPN::isOperator(char const c)
// {
// 	return (c == '+' or c == '-' or c == '*' or c == '/')
// }

long long	RPN::applyRPN( void )
{
	long long			result = 0;
	std::stack<int>		elements;
	size_t				i = 0;


	for (std::string::iterator it = _equation.begin(); i != std::string::npos; it = _equation.begin() + i)
	{
		i = _equation.find_first_of("0123456789+-*/", i + 1);
	}


		// std::cout << PURPLE << "IT = " << *it << END << std::endl;

	// i = _equation.find_first_of("0123456789", 0 + 1);

	// std::cout << GREEN << "DIST = " << i << END << std::endl;

	// it += _equation.find_first_of("0123456789", i);

	// std::cout << PURPLE << "IT = " << *it << END << std::endl;

	// it += _equation.find_first_of("0123456789", i);

	// std::cout << PURPLE << "IT = " << *it << END << std::endl;


	// result = _values.front();
	// _values.pop();

	// while (not _values.empty())
	// {
	// 	// std::cout << YELLOW << result << END << std::endl;
	// 	// std::cout << PURPLE << _operators.front() << END << std::endl;
	// 	// std::cout << GREEN << _values.front() << END << std::endl;

	// 	switch (_operators.front())
	// 	{
	// 		case '+' :
	// 			result += _values.front();
	// 			break ;
	// 		case '-' :
	// 			result = result - _values.front();
	// 			break ;
	// 		case '*' :
	// 			result *= _values.front();
	// 			break ;
	// 		case '/' :
	// 			if (result == 0)
	// 			{
	// 				std::cout << "Division by 0" << std::endl;
	// 				std::exit (1);
	// 			}
	// 			result = result / _values.front();
	// 			break ;
	// 	}
	// 	_operators.pop();
	// 	_values.pop();
	// }
	_result = result;
	
	return (getResult());
}


bool	RPN::isInvalidSyntax(const int &countValues, const int &countOperators, const char &lastElement)
{
	if (std::isdigit(lastElement))
	{
		std::cout << "Invalid syntax" << std::endl;
		return (1);
	}
	if (countValues <= countOperators)
	{
		std::cout << "To many operators" << std::endl;
		return (1);
	}
	else if (countValues > countOperators + 1)
	{
		std::cout << "To many values" << std::endl;
		return (1);
	}
	return (0);
}

bool	RPN::isInvalidSyntax(const int &countValues, const int &countOperators){
	return (countValues == 1 and countOperators == 1);
}

bool	RPN::isValidChar(const std::string &VALID_SET, char c){
	return (std::find(VALID_SET.begin(), VALID_SET.end(), c) != VALID_SET.end());
}

bool	RPN::isDigitUpper10(std::string &parameter, int i){
	return (std::isdigit(parameter[i]) and std::isdigit(parameter[i + 1]));
}

/*================================ Accessors =================================*/

long long	RPN::getResult( void ){
	return (_result);
}
