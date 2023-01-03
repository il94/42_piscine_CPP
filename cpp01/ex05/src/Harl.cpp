#include "../include/Harl.hpp"

Harl::Harl()
{
	this->_array[0] = &Harl::debug;
	this->_array[1] = &Harl::info;
	this->_array[2] = &Harl::warning;
	this->_array[3] = &Harl::error;
}

void	Harl::complain(std::string level)
{
	std::string listLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	size = (sizeof(listLevels) / sizeof(std::string));

	for (int i = 0; i < size; i++)
	{
		if (level == listLevels[i])
		{
			(this->*_array[i])();
			return ;
		}
	}
	std::cout << "Pff..." << std::endl;
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
