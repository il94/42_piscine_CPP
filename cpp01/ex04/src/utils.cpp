#include "../include/replace.h"

std::string getFileContent(std::ifstream &toRead)
{
	std::string	fileContent;
	std::string buffer;

	while (std::getline(toRead, buffer))
	{
		std::cout << "[" << buffer << "]" << std::endl;
		fileContent += buffer;
		if (not toRead.eof())
			fileContent += "\n";
	}
	return (fileContent);
}

const char	*generateOutputName(std::string &baseName)
{
	baseName.append(".replace");
	return (baseName.c_str());
}
