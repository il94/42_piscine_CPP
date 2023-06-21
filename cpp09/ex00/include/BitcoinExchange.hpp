#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <algorithm>

#include <vector>
#include <map>

#define BTCPRICE 26877.30

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define END "\033[0m"

bool	isInt(const char* str);
bool	isFloat(const char* str);

class BitcoinExchange : public std::map<std::string, float>
{
	public :

	/* Constructors */
	BitcoinExchange( const std::string & );
	BitcoinExchange( const BitcoinExchange & );
	~BitcoinExchange();

	/* Overloads */
	BitcoinExchange&	operator=( const BitcoinExchange & );

	/* Methods */
	
	void		printResultError(const std::string &src);
	void		printAdjustedResult(const std::string &date, const std::string &btcCount, const std::string &wrongDate);
	void		printResult(const std::string &date, const std::string &btcCount);
	void		evaluate( void );
	void		fill(const std::string &sourceFile);
	void		exitMessage(const std::string &message);
	bool		isValidDate(const std::string &str);
	bool		isValidValue(const std::string &str);

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
	std::map<std::string, std::vector<std::string>>	toEvaluate;
};

template <typename T>
void	displayVector(const T &vector, const std::string &name)
{
	if (vector.empty() == true)
		std::cout << RED  << name << " EMPTY" << END << std::endl;
	else
	{
		for (typename T::const_iterator it = vector.begin(); it != vector.end(); it++)
			std::cout << name + " = " << *it << std::endl;
	}
}

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