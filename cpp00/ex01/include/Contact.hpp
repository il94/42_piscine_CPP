#ifndef CONTACT
#define CONTACT

class	Contact
{
	public :

	void		createNewContact();
	void		displayContact();

	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	private :

	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickName;
	std::string	m_phoneNumber;
	std::string	m_darkestSecret;
};

#endif