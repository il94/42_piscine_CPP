#include "../include/BitcoinExchange.hpp"

/*=============================== Constructors ===============================*/

BitcoinExchange::BitcoinExchange(){
	std::cout << "[BitcoinExchange] Default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange( const std::string &src )
{
	std::cout << "[BitcoinExchange] Parameters constructor called." << std::endl;

	std::ifstream	dataBase("data.csv");
	if (not dataBase.good())
		throw (std::runtime_error("[ERROR] Error opening data.csv"));

	std::string						buffer;
	std::pair<std::string, float>	element;

	std::getline(dataBase, buffer);

	while (std::getline(dataBase, buffer))
	{
		if (buffer.find(',') != -1)
		{
			element.first = buffer.substr(0, buffer.find(','));
			element.second = std::atof(buffer.substr(buffer.find(',') + 1).c_str());
			insert(element);
		}
	}
}


BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ){
	std::cout << "[BitcoinExchange] Copy constructor called." << std::endl;
	*this = src;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "[BitcoinExchange] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &src)
{
	toEvaluate = src.toEvaluate;
	return (*this);
}

/*================================= Methods ==================================*/

bool	BitcoinExchange::isValidDate(const std::string &str)
{
	std::map<std::string, std::string>	date = splitDate(str, '-');

	if (date.size() != 3)
		return (false);

	for (std::map<std::string, std::string>::iterator	it = date.begin(); it != date.end(); it++)
	{
		if (not isInt(it->second.c_str()))
			return (false);
	}

	int	year = std::atoi(date["YEAR"].c_str());
	int	month = std::atoi(date["MONTH"].c_str());
	int	day = std::atoi(date["DAY"].c_str());

	if (year < 2009)
		return (false);
	if (month < 1 or month > 12)
		return (false);
	if (day < 1 or day > 31)
		return (false);

	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string &str)
{
	if (not isFloat(str.c_str()))
		return (false);
	
	float	value = atof(str.c_str());

	if (value < 0 or value > 1000)
		return (false);

	return (true);
}

void	BitcoinExchange::printResultError(const std::pair<std::string, std::string> &src)
{
	std::cerr << RED << src.second.substr(src.second.find('|') + 1) << END << std::endl;
}

void	BitcoinExchange::printResult(const std::pair<std::string, std::string> &src)
{

	std::cout << src.second << " btc "


	// At 2014-10-01, 0.3 bitcoins were worth $10

	std::cerr << RED << src.second.substr(src.second.find('|') + 1) << END << std::endl;
}

void	BitcoinExchange::evaluate( void )
{
	if (empty() == true)
		return ;
	
	displayMap(*this, "DATABASE");

	std::cout << std::endl;

	displayMap(toEvaluate, "TO EVAL");

	// float	

	for (std::map<std::string, std::string>::iterator it = toEvaluate.begin(); it != toEvaluate.end(); it++)
	{
		if (it->second.find('|') != -1)
			printResultError(*it);
		else
		{
			if (this->find(it->first) != this->end())
			{
				printResult(*it);
				// std::cout << GREEN << "FIND" << END << std::endl;
			}
			else
				std::cout << RED << "NOT FIND" << END << std::endl;

		}


		
	}

	// if (std::find(this->begin(), this->end(), 47115.9) != this->end())
	// if (this->find("2022-03-29") != this->end())
	// 	std::cout << GREEN << "FIND" << END << std::endl;
	// else
	// 	std::cout << RED << "NOT FIND" << END << std::endl;

}

void	BitcoinExchange::fill(const std::string &sourceFile)
{
	std::ifstream	file(sourceFile);
	if (not file.good())
		return ;
	
	toEvaluate.clear();

	std::pair<std::string, std::string>	element;

	std::string		buffer;
	bool			firstLine = true;

	while (std::getline(file, buffer))
	{
		if (firstLine and buffer == "date | value")
			firstLine = false;
		else if (buffer.find('|') != -1)
		{
			element.first = buffer.substr(0, buffer.find('|'));
			element.first.erase(remove_if(element.first.begin(), element.first.end(), isspace), element.first.end());
			element.second = buffer.substr(buffer.find('|') + 1);
			element.second.erase(remove_if(element.second.begin(), element.second.end(), isspace), element.second.end());

			if (not isValidDate(element.first))
				element.second += "|[ERROR] \"" + element.first + "\" is an invalid date";
			else if (not isValidValue(element.second))
				element.second += "|[ERROR] \"" + element.second + "\" is an invalid value";
			
			toEvaluate.insert(element);
		}
	}
	file.close();
}

std::map<std::string, std::string>	BitcoinExchange::splitDate(const std::string &str, char delimiter)
{
    std::map<std::string, std::string>	result;
	std::pair<std::string, std::string>	element;
    std::string::size_type				start = 0;
    std::string::size_type				end = str.find(delimiter);
	int									i = 0;

    while (end != std::string::npos)
    {
		if (i == 0)
			element.first = "YEAR";
		else if (i == 1)
			element.first = "MONTH";
		else if (i == 2)
			element.first = "DAY";
		else
			element.first = "DATA";
		element.second = str.substr(start, end - start);
        result.insert(element);
        start = end + 1;
        end = str.find(delimiter, start);
		i++;
    }
	if (i == 2)
		element.first = "DAY";
	else
		element.first = "DATA";
	element.second = str.substr(start);
	result.insert(element);

    return (result);
}

void	BitcoinExchange::exitMessage(const std::string &message)
{
	std::cerr << message << std::endl;
	exit (EXIT_FAILURE);
}

/*================================ Accessors =================================*/


