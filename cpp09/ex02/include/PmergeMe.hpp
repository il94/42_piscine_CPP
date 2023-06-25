#ifndef PMERGME
#define PMERGME

#include <iostream>
#include <climits>

#include <string>
#include <array>
#include <list>
#include <deque>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define END "\033[0m"

class PmergeMe
{
	public :

	/* Constructors */
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();

	/* Overloads */
	PmergeMe&	operator=(const PmergeMe &);

	/* Methods */

	void			push( int );
	void			displayTemp( void );
	void			display( void );
	void			sort( void );
	std::list<int>	sortList( std::list<int> );
	void			displayResult( void );

	/* Accessors */

	private :

	/* Attributes */

	std::list<int>	_elements;

	std::list<int>	_list;
	std::deque<int>	_deque;

	int				_timeList;
	int				_timeDeque;

};

#endif