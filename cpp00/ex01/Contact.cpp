#include "phonebook.h"

void	Contact::createNewContact()
{
	std::cout << "\t\t\t[        New contact        ]\n";
	while (m_firstName.size() == 0)
		printAndGetline("\t   First Name : ", m_firstName);
	while (m_lastName.size() == 0)
		printAndGetline("\t    Last Name : ", m_lastName);
	while (m_nickName.size() == 0)
		printAndGetline("\t    Nick Name : ", m_nickName);
	while (m_phoneNumber.size() == 0)
		printAndGetline("\t Phone Number : ", m_phoneNumber);
	while (m_darkestSecret.size() == 0)
		printAndGetline("His Darkest Secret ? : ", m_darkestSecret);
}

void	Contact::displayContact()
{
	std::cout << "\t   First Name : " << m_firstName << std::endl;
	std::cout << "\t    Last Name : " << m_lastName << std::endl;
	std::cout << "\t    Nick Name : " << m_nickName << std::endl;
	std::cout << "\t Phone Number : " << m_phoneNumber << std::endl;
	std::cout << "His Darkest Secret : " << m_darkestSecret << std::endl;
}

