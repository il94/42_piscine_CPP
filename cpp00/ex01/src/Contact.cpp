#include "../include/phonebook.h"

void	Contact::createNewContact()
{
	std::cout << "\t\t\t[        New contact        ]\n";
	while (_firstName.size() == 0)
		printAndGetline("\t   First Name : ", _firstName);
	while (_lastName.size() == 0)
		printAndGetline("\t    Last Name : ", _lastName);
	while (_nickName.size() == 0)
		printAndGetline("\t    Nick Name : ", _nickName);
	while (_phoneNumber.size() == 0)
		printAndGetline("\t Phone Number : ", _phoneNumber);
	while (_darkestSecret.size() == 0)
		printAndGetline(" His Darkest Secret ? : ", _darkestSecret);
}

void	Contact::displayContact()
{
	std::cout << "\t   First Name : " << _firstName << std::endl;
	std::cout << "\t    Last Name : " << _lastName << std::endl;
	std::cout << "\t    Nick Name : " << _nickName << std::endl;
	std::cout << "\t Phone Number : " << _phoneNumber << std::endl;
	std::cout << "   His Darkest Secret : " << _darkestSecret << std::endl;
}


std::string	Contact::getFirstName()
{
	return (_firstName);
}

std::string	Contact::getLastName()
{
	return (_lastName);
}

std::string	Contact::getNickName()
{
	return (_nickName);
}
