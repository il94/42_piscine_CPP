#include "ShrubberyCreationForm.hpp"

/*=============================== Constructors ===============================*/

ShrubberyCreationForm::ShrubberyCreationForm() : A_Form(), _target("unamed"){
	std::cout << "[ShrubberyCreationForm] Default constructor called." << std::endl;
	std::cout << getName() << " was created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	A_Form(), _target(target) {
	std::cout << "[ShrubberyCreationForm] Parameters constructor called." << std::endl;
	std::cout << getName() << " was created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src){
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

/*================================ Overloads =================================*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
}

/*================================= Methods ==================================*/



/*================================ Accessors =================================*/


