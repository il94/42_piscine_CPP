#include "../include/easyfind.h"

#define SIZE_MAX 5

void	printResult(std::vector<int>::iterator& it, std::vector<int>& array, int value)
{
	it = easyfind(array, value);
	if (it != array.end())
		std::cout << *it << " was found in array by SUUUUPER EASYFIND" << std::endl;
	else
		std::cout << value << " not found (last is returned)" << std::endl;
	std::cout << std::endl;
}

void	printElement(int i){
	std::cout << "[" << i << "] ";
}

int	getRandomNumber( void ){
	return (std::rand() % SIZE_MAX);
}

int	main( void )
{
	std::srand(time(NULL));

	std::vector<int>			array(SIZE_MAX, 0);
	std::vector<int>::iterator	it;

	std::generate(array.begin(), array.end(), getRandomNumber);

	std::for_each(array.begin(), array.end(), printElement);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	printResult(it, array, 0);
	printResult(it, array, 3);
	printResult(it, array, 5);

	return (0);
}