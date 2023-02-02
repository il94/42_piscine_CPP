#include "../include/Litteral.hpp"

/*=============================== Constructors ===============================*/

Litteral::Litteral() : _string("empty"), _value(0), _valueType(INVALID), _infValue(false),
	_char(0), _int(0), _float(0), _double(0){
}

Litteral::Litteral(const char* parameter) : _string(parameter), _value(atof(parameter)),
	_valueType(INVALID), _infValue(false), _char(0), _int(0), _float(0), _double(0){

	if (isChar())
	{
		_valueType = CHAR;
		_char = parameter[0];
		_value = static_cast<char>(_char);
	}
	else if (isInt())
	{
		_valueType = INT;
		_int = std::atoi(parameter);
	}
	else if (isDouble())
	{
		_valueType = DOUBLE;
		_double = std::atof(parameter);
	}
	else if (isFloat())
	{
		_valueType = FLOAT;
		_float = std::atof(parameter);
	}
}

Litteral::Litteral(const Litteral &src){
	*this = src;
}

Litteral::~Litteral(){
}

/*================================ Overloads =================================*/

Litteral& Litteral::operator=(const Litteral &src)
{
	_value = src._value;
	_valueType = src._valueType;
	_char = src._char;
	_int = src._int;
	_float = src._float;
	_double = src._double;
	return (*this);
}

/*================================= Methods ==================================*/

bool	Litteral::isChar( void ){
	return (_string.size() == 1 and not std::isdigit(_string[0]));
}

bool	Litteral::isInt( void )
{
	int	i = 0;

	if (_string[0] == '-')
		i++;
	while (std::isdigit(_string[i]))
		i++;
	return (static_cast<int>(_string.size()) == i);
}

bool	Litteral::isDouble( void )
{
	if (_string == "-inf" or _string == "+inf" or _string == "nan")
	{
		_infValue = true;
		return (true);
	}

	int	i = 0;

	if (_string[0] == '-')
		i++;
	while (std::isdigit(_string[i]))
		i++;
	if (_string[i] == '.' && std::isdigit(_string[i + 1]))
		i++;
	while (std::isdigit(_string[i]))
		i++;
	return (static_cast<int>(_string.size()) == i);
}

bool	Litteral::isFloat( void )
{
	if (_string == "-inff" or _string == "+inff" or _string == "nanf")
	{
		_infValue = true;
		return (true);
	}

	int	i = 0;

	if (_string[0] == '-')
		i++;
	while (std::isdigit(_string[i]))
		i++;
	if (_string[i] == '.' && std::isdigit(_string[i + 1]))
		i++;
	else
		return (false);
	while (std::isdigit(_string[i]))
		i++;
	if (_string[i] == 'f')
		i++;
	return (static_cast<int>(_string.size()) == i);
}

void	Litteral::printChar( void )
{
	std::cout << "char : ";

	if (_valueType == CHAR)
		std::cout << _char;
	else if (_infValue)
		std::cout << "impossible";
	else
	{
		_char = static_cast<char>(_value);
		if (not isprint(_char))
			std::cout << "Non displayable";
		else
			std::cout << _char;
	}
	std::cout << std::endl;
}

void	Litteral::printInt( void )
{
	std::cout << "int : ";

	if (_valueType == INT)
		std::cout << _int;
	else if (_infValue)
		std::cout << "impossible";
	else
	{
		_int = static_cast<int>(_value);
		std::cout << _int;
	}
	std::cout << std::endl;
}

void	Litteral::printFloat( void )
{
	std::cout << "float : ";

	if (_valueType == FLOAT)
	{
		std::cout << _float;
		if (decimalIsZero(_string) && not _infValue)
			std::cout << ".0";
		std::cout << "f";
	}
	else
	{
		_float = static_cast<float>(_value);
		std::cout << _float;
		if (_valueType != DOUBLE or (decimalIsZero(_string) && not _infValue))
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;
}

void	Litteral::printDouble( void )
{
	std::cout << "double : ";


	if (_valueType == DOUBLE)
	{
		std::cout << _double;
		if (decimalIsZero(_string) && not _infValue)
			std::cout << ".0";
	}
	else
	{
		_double = static_cast<double>(_value);
		std::cout << _double;
		if (_valueType != FLOAT or (decimalIsZero(_string) && not _infValue))
			std::cout << ".0";
	}
	std::cout << std::endl;
}


void	Litteral::printValues( void )
{
	if (_valueType == INVALID)
		std::cout << "Invalid parameter" << std::endl;
	else
	{
		printChar();
		printInt();
		printFloat();
		printDouble();
	}
}	