#include "../include/phonebook.h"

Phonebook::Phonebook() : m_number_of_contacts(0)
{
}

void	Phonebook::addContact()
{
	Contact		newContact;
	const int	MAX_CONTACTS(8);

	newContact.createNewContact();
	if (m_number_of_contacts >= MAX_CONTACTS)
	{
		for (int i(0); i < MAX_CONTACTS - 1; i++)
			m_contacts[i] = m_contacts[i + 1];
		m_contacts[MAX_CONTACTS - 1] = newContact;
	}
	else
	{
		m_contacts[m_number_of_contacts] = newContact;
		m_number_of_contacts++;
	}
}

void	Phonebook::displayPhonebook()
{
	std::cout << "\t\t ╔══════════╤══════════╤══════════╤══════════╗\n";
	std::cout << "\t\t ║     INDEX|FIRST NAME| LAST NAME|  NICKNAME║\n";
	std::cout << "\t\t ╠══════════╪══════════╪══════════╪══════════╣\n";
	if (m_number_of_contacts == 0)
		std::cout << "\t\t ║            You have no contact            ║\n";
	for (int i(0); i < m_number_of_contacts; i++)
	{
		std::cout << "\t\t ║" << "         " << i + 1 << "|";
		std::cout << std::setw(10) << displayStrInPhonebook(m_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << displayStrInPhonebook(m_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << displayStrInPhonebook(m_contacts[i].getNickName()) << "║\n";
	}
	std::cout << "\t\t ╚══════════╧══════════╧══════════╧══════════╝\n";
}

void	Phonebook::searchContact()
{
	int	index;

	displayPhonebook();
	if (m_number_of_contacts > 0)
	{
		std::cout << "\t\t\t[      Display contact      ]\n";
		index = convertInputToIndex(m_number_of_contacts);
		m_contacts[index].displayContact();
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
