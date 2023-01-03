#include "../include/Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string listLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	size = (sizeof(listLevels) / sizeof(std::string));

	for (int i = 0; i < size; i++)
	{
		if (level == listLevels[i])
		{
			for (int j = i; j < size; j++)
			{
				switch (j)
				{
					case 0:
						debug();
						continue;
					case 1:
						info();
						continue;
					case 2:
						warning();
						continue;
					case 3:
						error();
				}
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\n" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !\n" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n" << std::endl;
}
