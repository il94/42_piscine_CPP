#include "../include/Character.hpp"

/*=============================== Constructors ===============================*/

Character::Character() : I_Character(), _name("unamed"){
	std::cout << "[Character] Default constructor called." << std::endl;
	std::cout << getName() << " was created." << std::endl;
}

Character::Character(const Character &src) : I_Character(src){
	std::cout << "[Character] Copy constructor called." << std::endl;
	*this = src;
	std::cout << getName() << " was copied." << std::endl;
}

Character::~Character(){
	std::cout << "[Character] Default desstructor called." << std::endl;
}

/*================================ Overloads =================================*/

Character& Character::operator=(const Character &src)
{
	_name = src._name;
	_inventory[0] = src._inventory[0];
	_inventory[1] = src._inventory[1];
	_inventory[2] = src._inventory[2];
	_inventory[3] = src._inventory[3];
}

/*================================= Methods ==================================*/

void	Character::equip(A_Materia* m)
{

}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, I_Character& target)
{

}

/*================================ Accessors =================================*/

std::string const&	Character::getName( void ) const{
	return (_name);
}

