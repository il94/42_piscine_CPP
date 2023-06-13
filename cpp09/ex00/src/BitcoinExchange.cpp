#include "../include/BitcoinExchange.hpp"

/*=============================== Constructors ===============================*/

BitcoinExchange::BitcoinExchange(){
	std::cout << "[BitcoinExchange] Default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange( const std::string &src )
{
	std::cout << "[BitcoinExchange] Parameters constructor called." << std::endl;

	// try{
	// 	isCSVFile(src);
	// 	extractDataBase(src);

	// }
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
	dataBase = src.dataBase;
	result = src.result;
	return (*this);
}

/*================================= Methods ==================================*/



/*================================ Accessors =================================*/


