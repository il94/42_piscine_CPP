#include "../include/BitcoinExchange.hpp"

/*=============================== Constructors ===============================*/

BitcoinExchange::BitcoinExchange(){
	std::cout << "[BitcoinExchange] Default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange( const std::string &src )
{
	std::cout << "[BitcoinExchange] Parameters constructor called." << std::endl;

	std::ifstream	dataBase(src.c_str());
	if (not dataBase.good())
		throw (std::runtime_error("[ERROR] Error opening \"" + src + "\"."));

	std::string						buffer;
	std::pair<std::string, float>	element;

	std::getline(dataBase, buffer);

	while (std::getline(dataBase, buffer))
	{
		if (buffer.find(',') != std::string::npos)
		{
			element.first = buffer.substr(0, buffer.find(','));
			element.second = std::atof(buffer.substr(buffer.find(',') + 1).c_str());
			insert(element);
		}
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ) : std::map<std::string, float>(src) {
	std::cout << "[BitcoinExchange] Copy constructor called." << std::endl;
	*this = src;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "[BitcoinExchange] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &src)
{
	_toEvaluate = src._toEvaluate;
	return (*this);
}

/*================================= Methods ==================================*/

void	BitcoinExchange::evaluate( void )
{
	if (_toEvaluate.empty() == true)
	{
		std::cerr << RED << "[WARNING] File is empty " << END << std::endl;
		return ;
	}	

	std::map<std::string, float>::iterator adjust;

	for (t_Mstr_Vstr::iterator it = _toEvaluate.begin(); it != _toEvaluate.end(); it++)
	{
		for (std::vector<std::string>::iterator value = it->second.begin(); value != it->second.end(); value++)
		{
			if (value->find('|') != std::string::npos)
				printResultError(*value);
			else
			{
				if (this->find(it->first) != this->end())
					printResult(it->first, *value);
				else
				{
					adjust = (*this).upper_bound(it->first);

					if (adjust != this->begin())
					{
						adjust--;
						printAdjustedResult(adjust->first, *value, it->first);
					}
					else
						std::cerr << RED << "[WARNING] No results found for " << it->first << '.' << END << std::endl;
				}
			}
		}
	}
}

void	BitcoinExchange::fill(const std::string &sourceFile)
{
	std::ifstream	file(sourceFile.c_str());
	if (not file.good())
		throw (std::runtime_error("[ERROR] Error opening \"" + sourceFile + "\"."));
	
	_toEvaluate.clear();

	std::pair<std::string, std::string>	element;

	std::string		buffer;
	bool			firstLine = true;

	while (std::getline(file, buffer))
	{

		if (firstLine and buffer == "date | value")
			firstLine = false;
		else if (buffer.find('|') != std::string::npos)
		{
			element.first = buffer.substr(0, buffer.find('|'));
			element.first.erase(remove_if(element.first.begin(), element.first.end(), isspace), element.first.end());
			element.second = buffer.substr(buffer.find('|') + 1);
			element.second.erase(remove_if(element.second.begin(), element.second.end(), isspace), element.second.end());

			if (not isValidDate(element.first))
				element.second += "|[ERROR] \"" + element.first + "\" is an invalid date";
			else if (not isValidValue(element.second))
				element.second += "|[ERROR] \"" + element.second + "\" is an invalid value";
			
			_toEvaluate[element.first].push_back(element.second);
		}
	}
	file.close();
}

/*============================================================================*/

void	BitcoinExchange::printResult(const std::string &date, const std::string &btcCount)
{
	float	result = std::atof(btcCount.c_str()) * (*this)[date];

	std::cout << "At " << YELLOW << date << END;
	std::cout << ", " << PURPLE << btcCount << " btc" << END;

	if ((*this)[date] > BTCPRICE)
		std::cout << " were worth " << GREEN << result << " USD." << END << std::endl;
	else
		std::cout << " were worth " << RED << result << " USD." << END << std::endl;

}

void	BitcoinExchange::printAdjustedResult(const std::string &date, const std::string &btcCount, const std::string &wrongDate)
{
	float	result = std::atof(btcCount.c_str()) * (*this)[date];

	std::cerr << RED << "[WARNING] No results found for " << wrongDate << END;

	if (date == wrongDate)
		std::cerr << std::endl;
	else
	{
		std::cout << ", but at " << YELLOW << date << END;
		std::cout << ", " << PURPLE << btcCount << " btc" << END;

		if ((*this)[date] > BTCPRICE)
			std::cout << " were worth " << GREEN << result << " USD." << END << std::endl;
		else
			std::cout << " were worth " << RED << result << " USD." << END << std::endl;
	}
}

void	BitcoinExchange::printResultError(const std::string &src)
{
	std::cerr << RED << src.substr(src.find('|') + 1) << END << std::endl;
}

/*============================================================================*/

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

/*============================================================================*/

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

/*================================ Accessors =================================*/

t_Mstr_Vstr	BitcoinExchange::getToEvaluate( void ) const {
	return (_toEvaluate);
}

void	BitcoinExchange::setToEvaluate(const t_Mstr_Vstr &src){
	_toEvaluate = src;
}

