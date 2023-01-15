#include <iostream>

int main( void )
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Adresse de brain		: " << &brain << std::endl;
	std::cout << "Adresse de brain dans stringPTR	: " << stringPTR << std::endl;
	std::cout << "Adresse de brain dans stringREF	: " << &stringREF << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "Valeur de brain			: " << brain << std::endl;
	std::cout << "Valeur de brain par stringPTR	: " << *stringPTR << std::endl;
	std::cout << "Valeur de brain par stringREF	: " << stringREF << std::endl;
	return (0);
}
