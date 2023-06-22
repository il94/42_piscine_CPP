#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits> 
#include <vector>
#include <map>

#define BTCPRICE 26877.30

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define END "\033[0m"

typedef std::map<std::string, std::vector<std::string> > t_Mstr_Vstr;

void	exitMessage(const std::string &message);
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
	
	void	evaluate( void );
	void	fill(const std::string &sourceFile);

	void	printResult(const std::string &date, const std::string &btcCount);
	void	printAdjustedResult(const std::string &date, const std::string &btcCount, const std::string &wrongDate);
	void	printResultError(const std::string &src);

	bool	isValidDate(const std::string &str);
	bool	isValidValue(const std::string &str);

	std::map<std::string, std::string>	splitDate(const std::string &str, char delimiter);

	/* Accessors */
	t_Mstr_Vstr	getToEvaluate( void ) const ;
	void		setToEvaluate( const t_Mstr_Vstr & );
	
	private :

	/* Constructors */
	BitcoinExchange();

	/* Attributes */
	t_Mstr_Vstr	_toEvaluate;
};

#endif