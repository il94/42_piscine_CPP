#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"

class	Phonebook
{
	public :

	Phonebook();
	void		addContact();
	void		searchContact();

	private :

	std::string	displayInPhonebook(std::string str);
	void		displayPhonebook();

	Contact		m_contacts[8];
	int			m_number_of_contacts;
};

#endif