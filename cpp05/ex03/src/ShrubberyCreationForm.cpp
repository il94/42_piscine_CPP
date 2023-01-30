#include "../include/ShrubberyCreationForm.hpp"

/*=============================== Constructors ===============================*/

ShrubberyCreationForm::ShrubberyCreationForm() : A_Form(), _target("unamed"){
	std::cout << "[ShrubberyCreationForm] Default constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	A_Form("ShrubberyCreation", 145, 137), _target(target) {
	std::cout << "[ShrubberyCreationForm] Parameters constructor called." << std::endl;
	std::cout << *this << " was created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	A_Form(src){
	std::cout << "[ShrubberyCreationForm] Copy constructor called." << std::endl;
	*this = src;
	std::cout << *this << " was copied." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "[ShrubberyCreationForm] Default destructor called." << std::endl;
}

/*================================ Overloads =================================*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	_signed = src._signed;
	_target = src._target;
	return (*this);
}

/*================================= Methods ==================================*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	beExecuted(executor);
	std::ofstream	output((_target + "_shrubbery").c_str());

	output << "                                      &&& &&  & &&" << std::endl;
	output << "                                  && &\\/&\\|& ()|/ @, &&" << std::endl;
	output << "                                  &\\/(/&/&||/& /_/)_&/_&             ,@@@@@@@," << std::endl;
	output << "       _-_                     &() &\\/&|()|/&\\/ '%\" & ()        ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	output << "    /~~   ~~\\                 &_\\_&&_\\ |& |&&/&__%_/_& &&    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	output << " /~~         ~~\\      ###   &&   && & &| &| /& & % ()& /&&  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	output << "{               }    #o###   ()&_---()&\\&\\|&&-&&--%---()~   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	output << " \\  _-     -_  /   #####o###     &&     \\|||                %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	output << "   ~  \\\\ //  ~    #o#\\#|#/###            |||                `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	output << "_- -   | | _- _    ###\\|/#o#             |||                    |o|        | |         | |" << std::endl;
	output << "  _ -  | |   -_     # }|{  #             |||                    |.|        | |         | |" << std::endl;
	output << "\\  \\\\ // \\\\  \\\\ \\  \\\\ }|{   \\  \\ \\ , -=-~  .-^- _ \\  \\ \\ \\\\  \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

	output.close();
}