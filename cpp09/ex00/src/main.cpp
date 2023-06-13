#include "../include/BitcoinExchange.hpp"

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


bool	isDate(const std::string &str)
{
	return (true);
}

bool	isValidDataLine(const std::string &line)
{
	if (line.find('|') == -1)
		return (false);
	
	if (not isDate(line.substr(0, line.find('|'))))
		return (false);
	
	if (strtof(line.substr(line.find('|')).c_str() , NULL))
		return (false);
}

void	isValidInputFile(const std::string &fileName)
{
	std::ifstream	file(fileName);
	if (not file.good())
		throw (std::runtime_error("[ERROR] Error opening \"" + std::string(fileName) + "\""));

	std::string		buffer;
	while (std::getline(file, buffer))
	{
		if (not isValidDataLine(buffer))
			throw (std::runtime_error("[ERROR] " + buffer + " is an invalid line"));
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