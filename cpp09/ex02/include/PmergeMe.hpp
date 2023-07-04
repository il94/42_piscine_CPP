#ifndef PMERGME
#define PMERGME

#include <iostream>
#include <climits>
#include <ctime>
#include <algorithm>

#include <string>
#include <list>
#include <deque>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define END "\033[0m"

bool	operator<(const std::pair<int, int> &a, const std::pair<int, int> &b);

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
	void	push( int );
	void	run( void );
	void	displayResult( void );
	
	template <typename T, typename U>
	void	insert(T *copy, U n)
	{
		for (typename T::reverse_iterator it = copy->rbegin(); it != copy->rend(); it++)
		{
			if (*it < n)
			{
				copy->insert(it.base(), n);
				return ;
			}
		}
		copy->insert(copy->begin(), n);
	};

	/* Accessors */
	std::list<int>	getElements( void ) const;
	std::list<int>	getList( void ) const;
	std::deque<int>	getDeque( void ) const;
	double			getTimeList( void ) const;
	double			getTimeDeque( void ) const;

	void	setElements( const std::list<int> & );
	void	setList( const std::list<int> & );
	void	setDeque( const std::deque<int> & );
	void	setTimeList( const double & );
	void	setTimeDeque( const double & );

	private :

	/* Methods */
	void	sortList( void );
	void	sortDeque( void );

	void	mergeInsert( const std::list<std::pair<int, int> > & );
	void	mergeInsert( const std::deque<std::pair<int, int> > & );

	int		jacobSthal( int );

	template <typename T, typename U>
	T	splitToPair( U &toSplit )
	{
		T					pairs;
		std::pair<int, int>	pair;

		for (typename U::iterator it = toSplit.begin(); it != toSplit.end(); it++)
		{
			pair.first = *it;
			it++;
			pair.second = *it;

			if (pair.first > pair.second)
				std::swap(pair.first, pair.second);

			insert(&pairs, pair);
		}
		return (pairs);
	};

	/* Attributes */
	std::list<int>	_elements;

	std::list<int>	_list;
	std::deque<int>	_deque;

	double			_timeList;
	double			_timeDeque;
};

#endif