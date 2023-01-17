#include "../include/WrongAnimal.hpp"

/*=============================== Constructors ===============================*/

WrongAnimal::WrongAnimal() : _type("WrongMeta") {
	std::cout << "[WrongAnimal] Default constructor called. ";
	std::cout << getType() << " was created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "[WrongAnimal] Parameters constructor called. ";
	std::cout << getType() << " was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	std::cout << "[WrongAnimal] Copy constructor called. ";
	*this = src;
	std::cout << getType() << " was destroyed" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "[WrongAnimal] Default destructor called. ";
	std::cout << getType() << " was destroyed" << std::endl;
}

/*================================ Overloads =================================*/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	_type = src._type;
	return (*this);
}

/*================================= Methods ==================================*/

void	WrongAnimal::makeSound( void ) const{
	std::cout << "JE SUIS UN WRONG ANIMAL WTF" << std::endl;
}

/*================================ Accessors =================================*/

std::string	WrongAnimal::getType( void ) const {
	return (_type);
}
