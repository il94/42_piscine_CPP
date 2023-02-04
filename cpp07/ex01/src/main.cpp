#include "../include/iter.h"

#define SIZE_MAX 3

void	badDisplay(int element)
{
	std::cout << element << std::endl;
}

int main( void )
{
	int			arrayInt[] = {1, 2, 3};
	char		arrayChar[] = {'a', 'b', 'c'};
	std::string	arrayString[] = {"Hello", "Hola", "Sawubona (bonjour en Zoulou)"};

	iter(arrayInt, SIZE_MAX, badDisplay);
	std::cout << std::endl;

	iter(arrayChar, SIZE_MAX, badDisplay);

	// iter(arrayString, SIZE_MAX, badDisplay); (ne compile pas)

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	iter(arrayInt, SIZE_MAX, display<int>);
	std::cout << std::endl;

	iter(arrayChar, SIZE_MAX, display<char>);
	std::cout << std::endl;

	iter(arrayString, SIZE_MAX, display<std::string>);

	return (0);
}