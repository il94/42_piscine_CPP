#include "../include/replace.h"

std::string getFileContent(std::ifstream &toRead)
{
	std::string	fileContent;
	std::string buffer;

	while (getline(toRead, buffer))
		fileContent += buffer += "\n";
	return (fileContent);
}

const char	*generateOutputName(std::string baseName)
{
	baseName.append(".replace");
	return (baseName.c_str());
}
