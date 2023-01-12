#include <iostream>

void	printToUpper(char c)
{
	if (c >= 'a' && c <= 'z')
		std::cout << (char)(c - 32);
	else
		std::cout << c;
}

int main(int ac, char **av)
{
	std::string	convert;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			convert = av[i];
			if (not convert.empty())
			{
				for (int j = 0; j < (int)convert.size(); j++)
					printToUpper(convert[j]);
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
