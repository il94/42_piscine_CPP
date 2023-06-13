#include "../include/BitcoinExchange.hpp"

bool	strIsDigit(const std::string &str)
{
	int	i = 0;

	while (i < str.size())
	{
		// std::cout << RED << str[i] << END << std::endl;
		if (std::isdigit(str[i]) == false and str[i] != ' ' and str[i] != '.')
		{
			if (str[i] == '.' and i != 0 and str[i - 1] )
			return (false);
		}
		i++;
	}

	return (true);
}

std::vector<std::string>	split(const std::string &str, char delimiter)
{
    std::vector<std::string>	result;
    std::string::size_type		start = 0;
    std::string::size_type		end = str.find(delimiter);

    while (end != std::string::npos)
    {
        result.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    result.push_back(str.substr(start));

    return (result);
}

bool	isCSVFile( const std::string &src ) {
	return (not src.empty() and src.rfind(".csv") != -1);
}

void	isValidInput(const int &numberParameters, const char *fileName)
{
	std::ifstream	dataBase("data.csv");
	if (not dataBase.good())
		throw (std::runtime_error("[ERROR] Error opening data.csv"));

	if (numberParameters != 1)
	{
		if (numberParameters < 1)
			throw (std::runtime_error("[ERROR] Need an argument"));
		else
			throw (std::runtime_error("[ERROR] Too many arguments"));
	}

	std::ifstream	file(fileName);
	if (not file.good())
		throw (std::runtime_error("[ERROR] Error opening \"" + std::string(fileName) + "\""));
}


bool	isValidDate(const std::string &str)
{
	std::vector<std::string>	date = split(str, '-');
	int							element;

	for (std::vector<std::string>::iterator	it = date.begin(); it != date.end(); it++)
	{
		// std::cout << YELLOW << *it << END << std::endl;
		if (not strIsDigit(*it))
			return (false);
	}

	if (date.size() != 3)
		return (false);

	return (true);
}

bool	isValidValue(const std::string &str)
{
	std::cout << YELLOW << str << END << std::endl;
	if (not strIsDigit(str))
		return (false);
	
	return (true);
}


bool	isValidDataLine(const std::string &line)
{

	std::cout << GREEN << line << END << std::endl;

	if (line.find('|') == -1)
		return (false);
	
	if (not isValidDate(line.substr(0, line.find('|'))))
		return (false);

	if (not isValidValue(line.substr(line.find("| ") + 2)))
		return (false);

	return (true);
}

void	isValidInputFile(const std::string &fileName)
{
	std::ifstream	file(fileName);
	if (not file.good())
		throw (std::runtime_error("[ERROR] Error opening \"" + std::string(fileName) + "\""));

	std::string		buffer;
	bool			firstLine = true;
	while (std::getline(file, buffer))
	{
		if (firstLine)
		{
			if (buffer != "date | value")
				throw (std::runtime_error("[ERROR] " + buffer + " is an invalid line"));
			firstLine = false;
		}
		else
		{
			if (not isValidDataLine(buffer))
				throw (std::runtime_error("[ERROR] " + buffer + " is an invalid line"));
		}
	}

}

int	main(int ac, char **av)
{
	try{
		isValidInput(ac - 1, *(av + 1));
		isValidInputFile(*(av + 1));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}