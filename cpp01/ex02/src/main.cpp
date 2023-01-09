#include <iostream>

int main( void )
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Adresse de brain     : " << &brain << std::endl;
	std::cout << "Adresse de stringPTR : " << stringPTR << std::endl;
	std::cout << "Adresse de stringREF : " << &stringREF << std::endl;
	std::cout << "=======================" << std::endl;
	std::cout << "Valeur de brain     : " << brain << std::endl;
	std::cout << "Valeur de stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur de stringPTR : " << stringREF << std::endl;
	return (0);
}
