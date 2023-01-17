#include "../include/WrongCat.hpp"

/*=============================== Constructors ===============================*/

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "[WrongCat] Default constructor called. " << std::endl;
	std::cout << getType() << " was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "[WrongCat] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getType() << " was copied" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "[WrongCat] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meeeoooowwwww" << std::endl;
}
