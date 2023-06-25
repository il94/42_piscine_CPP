#include "../include/PmergeMe.hpp"

/*=============================== Constructors ===============================*/

PmergeMe::PmergeMe(){
	std::cout << "[PmergeMe] Default constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src){
	std::cout << "[PmergeMe] Copy constructor called." << std::endl;
}

PmergeMe::~PmergeMe(){
	std::cout << "[PmergeMe] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

PmergeMe&	PmergeMe::operator=(const PmergeMe &src)
{
	_elements = src._elements;

	_list = src._list;
	_deque = src._deque;

	_timeList = src._timeList;
	_timeDeque = src._timeDeque;

	return (*this);
}

/*================================= Methods ==================================*/

void	PmergeMe::push(int src)
{
	_elements.push_back(src);

	_list.push_back(src);
	_deque.push_back(src);
}

void	PmergeMe::displayTemp( void )
{
	std::cout << BLUE << "PMERGME ELEMENTS : " << std::endl;

	for (std::list<int>::iterator it = _elements.begin(); it != _elements.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << END << std::endl;

	std::cout << std::endl;
}

void	PmergeMe::display( void )
{
	// std::cout << BLUE << "PMERGME ELEMENTS : " << std::endl;

	// for (std::list<int>::iterator it = _elements.begin(); it != _elements.end(); it++)
	// {
	// 	std::cout << *it << ' ';
	// }
	// std::cout << END << std::endl;

	// std::cout << std::endl;

	std::cout << YELLOW << "PMERGME LIST : " << std::endl;

	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << END << std::endl;

	std::cout << std::endl;

	std::cout << PURPLE << "PMERGME DEQUE : " << std::endl;
	
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << END << std::endl;
	std::cout << std::endl;
}

void	PmergeMe::sort( void )
{
	std::cout << YELLOW;
	_list = sortList(_list);
	std::cout << END << std::endl;

	// for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	// 	std::cout << GREEN << *it << ' ' << END;
	// std::cout << std::endl;

	// std::cout << PURPLE;
	// sortDeque();
	// std::cout << END << std::endl;
}

std::list<int>	PmergeMe::sortList( std::list<int> list )
{
	if (list.size() == 1)
		return (list);

	std::list<int>	result = list;

	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << BLUE << *it << ' ' << END;
	std::cout << std::endl;

	bool	odd = false;
	int		last;

	if (result.size() % 2 != 0)
		odd = true;
	
	if (odd)
	{
		last = result.back();
		result.pop_back();
	}
	
	std::list<std::pair<int, int> >	pairs;
	std::pair<int, int>				pair;
	
	while (result.empty() == false)
	{
		pair.first = result.front();
		result.pop_front();
		pair.second = result.front();
		result.pop_front();

		// if (pair.first > pair.second)
		// {
		// 	int temp = pair.second;
		// 	pair.second = pair.first;
		// 	pair.first = temp;
		// }
		pairs.push_back(pair);
	}

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::cout << "[ " << it->first << " , " << it->second << " ] ";

		result.push_back(std::max(it->first, it->second));
	}
	std::cout << std::endl;

	for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
		std::cout << PURPLE << *it << ' ' << END;
	std::cout << std::endl;

	if (odd)
		std::cout << "LAST = " << last << std::endl;

	std::cout << std::endl;

	if (result.size() != 1)
		result = sortList(result);

	// if (odd)


	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		std::cout << YELLOW << "[ " << it->first << " , " << it->second << " ] " << END;
	std::cout << std::endl;
	for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
		std::cout << GREEN << *it << ' ' << END;
	std::cout << std::endl;



	// if (result.size() == 1)
	// {
	// 	std::cout << YELLOW << "IF" << END << std::endl;

		// for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
		// 	std::cout << GREEN << *it << ' ' << END;
		// std::cout << std::endl;
	// 	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	// 		std::cout << YELLOW << "[ " << it->first << " , " << it->second << " ] " << END;
	// 	std::cout << std::endl;
	// 	std::cout << std::endl;

	// 	return (result);
	// }
	// else
	// {
	// 	result = sortList(result);

	// 	for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
	// 		std::cout << GREEN << *it << ' ' << END;
	// 	std::cout << std::endl;
	// 	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	// 		std::cout << YELLOW << "[ " << it->first << " , " << it->second << " ] " << END;
	// 	std::cout << std::endl;
	// 	std::cout << std::endl;



	// }


	// for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	// {
	// 	if (it->first >= )
	// }




	return (result);
	
}

void	PmergeMe::displayResult( void )
{
	std::cout << "Unsorted sequence : " << BLUE << std::endl << '\t';
	for (std::list<int>::iterator it = _elements.begin(); it != _elements.end(); it++)
		std::cout << *it << ' ';
	std::cout << END << std::endl;

	std::cout << std::endl;

	std::cout << "Sorted sequence : " << GREEN << std::endl << '\t';
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << ' ';
	std::cout << END << std::endl;

	std::cout << std::endl;

	std::cout << "Time to process a range of " << BLUE << _elements.size() << END << " elements with std::list : " << std::endl;

	if (_timeList < _timeDeque)
		std::cout << GREEN << '\t' << _timeList << END << std::endl;
	else if (_timeList > _timeDeque)
		std::cout << RED << '\t' << _timeList << END << std::endl;
	else
		std::cout << YELLOW << '\t' << _timeList << END << std::endl;
	
	std::cout << std::endl;

	std::cout << "Time to process a range of " << BLUE << _elements.size() << END << " elements with std::deque : " << std::endl;
	if (_timeDeque < _timeList)
		std::cout << GREEN << '\t' << _timeDeque << END << std::endl;
	else if (_timeDeque > _timeList)
		std::cout << RED << '\t' << _timeDeque << END << std::endl;
	else
		std::cout << YELLOW << '\t' << _timeDeque << END << std::endl;
}

/*================================ Accessors =================================*/
