#include "../include/phonebook.h"

Phonebook::Phonebook() : _number_of_contacts(0)
{
}

void	Phonebook::addContact()
{
	Contact		newContact;
	const int	MAX_CONTACTS(8);

	newContact.createNewContact();
	if (_number_of_contacts >= MAX_CONTACTS)
	{
		for (int i(0); i < MAX_CONTACTS - 1; i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[MAX_CONTACTS - 1] = newContact;
	}
	else
	{
		_contacts[_number_of_contacts] = newContact;
		_number_of_contacts++;
	}
}

void	Phonebook::displayPhonebook()
{
	std::cout << "\t\t ╔══════════╤══════════╤══════════╤══════════╗\n";
	std::cout << "\t\t ║     INDEX|FIRST NAME| LAST NAME|  NICKNAME║\n";
	std::cout << "\t\t ╠══════════╪══════════╪══════════╪══════════╣\n";
	if (_number_of_contacts == 0)
		std::cout << "\t\t ║            You have no contact            ║\n";
	for (int i(0); i < _number_of_contacts; i++)
	{
		std::cout << "\t\t ║" << "         " << i + 1 << "|";
		std::cout << std::setw(10) << displayStrInPhonebook(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << displayStrInPhonebook(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << displayStrInPhonebook(_contacts[i].getNickName()) << "║\n";
	}
	std::cout << "\t\t ╚══════════╧══════════╧══════════╧══════════╝\n";
}

void	Phonebook::searchContact()
{
	int	index;

	displayPhonebook();
	if (_number_of_contacts > 0)
	{
		std::cout << "\t\t\t[      Display contact      ]\n";
		index = convertInputToIndex(_number_of_contacts);
		if (index >= 0)
			_contacts[index].displayContact();
	}
}

std::string	Phonebook::displayStrInPhonebook(std::string str)
{
	std::string	result;

	result = str.substr(0, 10);
	if (str.size() > 10)
		result[9] = '.';
	return (result);
}
