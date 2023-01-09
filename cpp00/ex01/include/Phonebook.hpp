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

	std::string	displayStrInPhonebook(std::string str);
	void		displayPhonebook();

	Contact		_contacts[8];
	int			_number_of_contacts;
};

#endif