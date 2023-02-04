#include "../include/Array.hpp"

#define SIZE_MAX 3

int main( void )
{
	Array<int>	myIntArray(SIZE_MAX);
	Array<char>	myCharArray(SIZE_MAX);

	for (int i = 0; i < SIZE_MAX; i++)
	{
		myIntArray[i] = i;
		myCharArray[i] = static_cast<char>(i + 65);
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	try{
		std::cout << myIntArray[SIZE_MAX + 1] << std::endl;
	}
	catch(Array<int>::ArrayException& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		std::cout << myCharArray[-1] << std::endl;
	}
	catch(Array<char>::ArrayException& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		for (int i = 0; i < SIZE_MAX; i++)
			std::cout << "INT " << myIntArray[i] << std::endl;
		for (int i = 0; i < SIZE_MAX; i++)
			std::cout << "CHAR " << myCharArray[i] << std::endl;
	}
	catch(Array<int>::ArrayException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	std::cout << "Size array : " << myIntArray.size() << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	Array<int> myNewIntArray(myIntArray);
	std::cout << std::endl;

	for (int i = 0; i < SIZE_MAX; i++)
		myNewIntArray[i] = i + 3;

	for (int i = 0; i < SIZE_MAX; i++)
		std::cout << "INT " << myIntArray[i] << std::endl;
	for (int i = 0; i < SIZE_MAX; i++)
		std::cout << "NEW INT " << myNewIntArray[i] << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	return (0);
}