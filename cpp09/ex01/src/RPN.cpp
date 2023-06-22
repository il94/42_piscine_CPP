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
			exitMessage("[ERROR] Caracter invalid");
		else if (isDigitUpper10(_equation, i))
			exitMessage("[ERROR] Values must be between 0 and 9");
		else if (_equation[i] != ' ')
		{
			if (std::isdigit(_equation[i]))
				countValues++;
			else
				countOperators++;
			lastElement = _equation[i];
		}
		checkSyntax(countValues, countOperators);
	}
	checkSyntax(countValues, countOperators, lastElement);
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
	_result = src._result;
	return (*this);
}

/*================================= Methods ==================================*/

long long	RPN::resolve( void )
{
	std::stack<long long>	elements;
	size_t					i = 0;
	int						value;

	for (std::string::iterator it = _equation.begin(); i != std::string::npos; it = _equation.begin() + i)
	{
		if (std::isdigit(*it))
			elements.push(*it - 48);
		else
		{
			value = elements.top();
			elements.pop();
			switch (*it)
			{
				case '+' :
					elements.top() += value;
					break ;
				case '-' :
					elements.top() -= value;
					break ;
				case '*' :
					elements.top() *= value;
					break ;
				case '/' :
					if (value == 0 or elements.top() == 0)
						exitMessage("[ERROR] Division by 0");
					elements.top() /= value;
					break ;
			}
		}

		i = _equation.find_first_of("0123456789+-*/", i + 1);
	}

	setResult(elements.top());
	
	return (getResult());
}


void	RPN::checkSyntax(const int &countValues, const int &countOperators, const char &lastElement)
{
	if (std::isdigit(lastElement))
		exitMessage("[ERROR] Invalid syntax");
	if (countValues <= countOperators)
		exitMessage("[ERROR] To many operators");
	else if (countValues > countOperators + 1)
		exitMessage("[ERROR] To many values");
}

void	RPN::checkSyntax(const int &countValues, const int &countOperators)
{
	if (countValues == 1 and countOperators == 1)
		exitMessage("[ERROR] To many values");
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

void		RPN::setResult( const long long &src ){
	_result = src;
}
