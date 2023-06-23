#ifndef PMERGME
#define PMERGME

#include <iostream>
#include <climits>

#include <string>
#include <vector>
#include <list>

#define RED "\033[31m"
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

	void	push_back( int );

	/* Accessors */

	private :

	/* Attributes */
	std::list<int>	_list;

};

#endif