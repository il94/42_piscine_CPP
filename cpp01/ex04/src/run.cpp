#include "../include/replace.h"

static std::string	replace(std::string file, std::string s1, std::string s2)
{
	std::string result;
	int	startIndex = 0;
	int endIndex = file.find(s1, startIndex);

	while (endIndex >= 0)
	{
		result.append(file.substr(startIndex, endIndex - startIndex));
		result.append(s2);
		startIndex = endIndex + s1.size();
		endIndex = file.find(s1, startIndex);
	}
	result.append(file.substr(startIndex, endIndex - startIndex));
	return (result);
}

void	run(std::string inputFile, std::string s1, std::string s2)
{
	std::ifstream	input(inputFile.c_str());
	if (!input.good())
	{
		std::cout << "Invalid input file\n";
		quick_exit(EXIT_FAILURE);
	}
	std::ofstream	output(generateOutputName(inputFile));
	if (!output.good())
	{
		std::cout << "Output creation failed\n";
		input.close();
		quick_exit(EXIT_FAILURE);
	}
	output << replace(getFileContent(input), s1, s2);
	input.close();
	output.close();
}