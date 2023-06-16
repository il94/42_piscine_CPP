#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <algorithm>

#include <vector>
#include <map>

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define END "\033[0m"

bool	isInt(const char* str);
bool	isFloat(const char* str);

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
	
	void		fill(const std::string &sourceFile);
	void		exitMessage(const std::string &message);
	bool		isValidDate(const std::string &str);

	std::map<std::string, std::string>	splitDate(const std::string &str, char delimiter);

	/* Accessors */
	std::vector<std::string>		getDataBase( void ) const ;
	std::map<std::string, float>	getResult( void ) const ;

	void							setDataBase( const std::vector<std::string> & );
	void							setResult( const std::map<std::string, float> & );
	
	private :

	/* Constructors */
	BitcoinExchange();

	/* Attributes */
	std::map<std::string, float>	dataBase;
	std::map<std::string, std::string>	result;
};

template <typename T>
void	displayMap(const T &map, const std::string &name)
{
	if (map.empty() == true)
		std::cout << RED  << name << " EMPTY" << END << std::endl;
	else
	{
		for (typename T::const_iterator it = map.begin(); it != map.end(); it++)
			std::cout << name + " " << it->first << " = " << it->second << std::endl;
	}
}

#endif