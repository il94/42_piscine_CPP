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

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif