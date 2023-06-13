#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>

#include <vector>
#include <map>

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define END "\033[0m"


bool	isCSVFile( const std::string &src );

class BitcoinExchange
{
	public :

	/* Constructors */
	BitcoinExchange( const std::string & );
	BitcoinExchange( const BitcoinExchange & );
	~BitcoinExchange();

	/* Overloads */
	BitcoinExchange&	operator=( const BitcoinExchange & );

	/* Methods */
	

	/* Accessors */
	std::vector<std::string>		getDataBase( void ) const ;
	std::map<std::string, float>	getResult( void ) const ;

	void							setDataBase( const std::vector<std::string> & );
	void							setResult( const std::map<std::string, float> & );
	
	private :

	/* Constructors */
	BitcoinExchange();

	/* Attributes */
	std::vector<std::string>		dataBase;
	std::map<std::string, float>	result;
};

#endif