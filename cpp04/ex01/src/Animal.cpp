#include "../include/Animal.hpp"

/*=============================== Constructors ===============================*/

Animal::Animal() : _type("Meta"), _brain(new Brain){
	std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type), _brain(new Brain){
	std::cout << "[Animal] Parameters constructor called." << std::endl;
}

Animal::Animal(const Animal &src) : _brain(new Brain){
	std::cout << "[Animal] Copy constructor called." << std::endl;
	*this = src;
}

Animal::~Animal(){
	std::cout << "[Animal] Default destructor called." << std::endl;
	delete _brain;
	std::cout << getType() << " was destroyed" << std::endl;
}

/*================================ Overloads =================================*/

Animal& Animal::operator=(const Animal &src)
{
	_type = src._type;
	*_brain = *(src._brain);
	return (*this);
}

/*================================= Methods ==================================*/

void	Animal::makeSound( void ) const{
}

void	Animal::wants( void ) const
{
	std::cout << getType() << " wants " <<  _brain->getRandomIdea() << std::endl;
}

/*================================ Accessors =================================*/

std::string	Animal::getType( void ) const {
	return (_type);
}
