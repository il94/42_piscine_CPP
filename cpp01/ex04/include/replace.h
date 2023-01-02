#ifndef REPLACE_H
#define REPLACE_H

#include <iostream>
#include <fstream>
#include <cstdlib>

/* utils.cpp */
std::string	getFileContent(std::ifstream &toRead);
const char	*generateOutputName(std::string baseName);

/* run.cpp*/
void		run(char *inputFile, std::string s1, std::string s2);

/* checkData.cpp*/
bool		isValidInput(int nbParameters, char *s1);

/* main.cpp */
int 		main(int ac, char **av);

#endif