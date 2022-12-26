#include "phonebook.h"

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
		std::cout << displayInPhonebook(m_contacts[i].m_firstName) << "|";
		std::cout << displayInPhonebook(m_contacts[i].m_lastName) << "|";
		std::cout << displayInPhonebook(m_contacts[i].m_nickName) << "║\n";
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

std::string	Phonebook::displayInPhonebook(std::string str)
{
	std::string	result;
	int		size_spaces = 10 - str.size();

	if (str.size() > 10)
	{
		result = str;
		result[9] = '.';
		result = result.substr(0, 10);
	}
	else
	{
		for (int i(0); i < size_spaces; i++)
			result += ' ';
		result += str;
	}
	return (result);
}
