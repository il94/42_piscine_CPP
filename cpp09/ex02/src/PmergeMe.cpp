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
	return (*this);
}

/*================================= Methods ==================================*/

void	PmergeMe::push_back(int src)
{
	_list.push_back(src);
}


/*================================ Accessors =================================*/
