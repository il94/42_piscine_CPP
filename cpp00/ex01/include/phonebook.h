#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Phonebook.hpp"
#include "Contact.hpp"

void	printAndGetline(std::string to_print, std::string &input);
int		convertInputToIndex(int index_max);

#endif