#include "phonebook.h"

int	main()
{
	Phonebook	phoneBook;

	for (std::string input; input != "EXIT" && input != "exit" && input != "3";)
	{
		std::cout << "\t\t\t[         PhoneBook         ]\n";
		printAndGetline("\t\t\t   [ADD]  [SEARCH]  [EXIT]   \n\t\t\t", input);
		if (input == "ADD" || input == "add" || input == "1")
			phoneBook.addContact();
		else if (input == "SEARCH" || input == "search" || input == "2")
			phoneBook.searchContact();
	}
	return (0);
}