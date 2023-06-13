#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>

#include <vector>
#include <map>

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