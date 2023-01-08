#include "../include/Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string listLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	size = (sizeof(listLevels) / sizeof(std::string));

	for (int i = 0; i < size; i++)
	{
		if (level == listLevels[i])
		{
			switch (i)
			{
				case 0:
					debug();
					__attribute__((fallthrough));
				case 1:
					info();
					__attribute__((fallthrough));
				case 2:
					warning();
					__attribute__((fallthrough));
				case 3:
					error();
					break ;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::info()
{
	std::cout << std::endl << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning()
{
	std::cout << std::endl << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << std::endl << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
