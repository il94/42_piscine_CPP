#ifndef PMERGME
#define PMERGME

class PmergeMe
{
	public :

	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();

	PmergeMe&	operator=(const PmergeMe &);
};


#endif