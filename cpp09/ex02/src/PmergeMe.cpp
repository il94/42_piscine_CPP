#include "../include/PmergeMe.hpp"

/*=============================== Constructors ===============================*/

PmergeMe::PmergeMe(){
	std::cout << "[PmergeMe] Default constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src){
	*this = src;
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

void	PmergeMe::run( void )
{
	time_t start, end;

	start = std::clock();
	sortList();
	end = std::clock();
	_timeList = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	start = std::clock();
	sortDeque();
	end = std::clock();
	_timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC;
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

	std::cout << "Time to process a range of " << BLUE << _elements.size() << END << " elements with std::list" << std::endl;

	if (_timeList < _timeDeque)
		std::cout << GREEN;
	else if (_timeList > _timeDeque)
		std::cout << RED;
	else
		std::cout << YELLOW;
	std::cout << '\t' << _timeList << END << " sec (CPU time)" << std::endl;
	
	std::cout << std::endl;

	std::cout << "Time to process a range of " << BLUE << _elements.size() << END << " elements with std::deque" << std::endl;
	if (_timeDeque < _timeList)
		std::cout << GREEN;
	else if (_timeDeque > _timeList)
		std::cout << RED;
	else
		std::cout << YELLOW;

	std::cout << '\t' << _timeDeque << END << " sec (CPU time)" << std::endl;
}

void	PmergeMe::sortList( void )
{
	bool	odd = false;
	int		last;

	if (_list.size() % 2 != 0)
	{
		odd = true;
		last = _list.back();
		_list.pop_back();
	}

	std::list<std::pair<int, int> >	pairs;
	pairs = splitToPair<std::list<std::pair<int, int> > >(_list);

	_list.clear();

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		_list.push_back(it->second);
	if (odd)
		pairs.push_back(std::pair<int, int> (last, 0));

	mergeInsert(pairs);
}

void	PmergeMe::sortDeque( void )
{
	bool	odd = false;
	int		last;

	if (_deque.size() % 2 != 0)
	{
		odd = true;
		last = _deque.back();
		_deque.pop_back();
	}

	std::deque<std::pair<int, int> >	pairs;
	pairs = splitToPair<std::deque<std::pair<int, int> > >(_deque);

	_deque.clear();

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		_deque.push_back(it->second);
	if (odd)
		pairs.push_back(std::pair<int, int> (last, 0));

	mergeInsert(pairs);
}

void	PmergeMe::mergeInsert( const std::list<std::pair<int, int> > &pairs )
{
	_list.push_front(pairs.front().first);

	size_t	target = 0;
	size_t	oldTarget = 0;
	size_t	jacobTarget = 2;
	size_t	i = 0;

	std::list<std::pair<int, int> >::const_iterator it;

	while (_list.size() != _elements.size())
	{
		if (target > oldTarget + 1)
			target--;
		else
		{
			oldTarget = jacobSthal(jacobTarget - 1);
			target = jacobSthal(jacobTarget);
			jacobTarget++;
			while (target > pairs.size() - 1)
				target--;
		}
		it = pairs.begin();
		i = 0;
		while (i < target)
		{
			i++;
			it++;
		}
		insert(&_list, it->first);
	}
}

void	PmergeMe::mergeInsert( const std::deque<std::pair<int, int> > &pairs )
{
	_deque.push_front(pairs[0].first);

	size_t	target = 0;
	size_t	oldTarget = 0;
	size_t	jacobTarget = 2;

	while (_deque.size() != _elements.size())
	{
		if (target > oldTarget + 1)
			target--;
		else
		{
			oldTarget = jacobSthal(jacobTarget - 1);
			target = jacobSthal(jacobTarget);
			jacobTarget++;
			while (target > pairs.size() - 1)
				target--;
		}
		insert(&_deque, pairs[target].first);
	}
}

int		PmergeMe::jacobSthal( int n )
{
	if (n == 0 or n == 1)
		return (n);
	return (jacobSthal(n - 1) + 2 * jacobSthal(n - 2));
}

/*================================ Accessors =================================*/

std::list<int>	PmergeMe::getElements( void ) const {
	return (_elements);
}

std::list<int>	PmergeMe::getList( void ) const {
	return (_list);
}

std::deque<int>	PmergeMe::getDeque( void ) const {
	return (_deque);
}

double			PmergeMe::getTimeList( void ) const {
	return (_timeList);
}

double			PmergeMe::getTimeDeque( void ) const {
	return (_timeDeque);
}


void	PmergeMe::setElements(const std::list<int> &src) {
	_elements = src;
}

void	PmergeMe::setList(const std::list<int> &src) {
	_list = src;
}

void	PmergeMe::setDeque(const std::deque<int> &src) {
	_deque = src;
}

void	PmergeMe::setTimeList(const double &src) {
	_timeList = src;
}

void	PmergeMe::setTimeDeque(const double &src) {
	_timeDeque = src;
}
