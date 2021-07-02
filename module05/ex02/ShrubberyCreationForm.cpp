#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	Form("Shrubbery creation form",
		145,
		137,
		target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) :
	Form(copy) {
	
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm & form) {
	if (this != &form) {
		Form::operator=(form);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
	std::ofstream file;

	file.open((this->getTarget() + "_shrubbery").c_str(), std::ios_base::app);
	if (file.is_open()) {
		file << "                 # #### ####			" << std::endl;
        file << "               ### \\/#|### |/####		" << std::endl;
        file << "              ##\\/#/ \\||/##/_/##/_#	" << std::endl;
        file << "            ###  \\/###|/ \\/ # ###	" << std::endl;
        file << "          ##_\\_#\\_\\## | #/###_/_####" << std::endl;
        file << "         ## #### # \\ #| /  #### ##/##	" << std::endl;
        file << "          __#_--###`  |{,###---###-~	" << std::endl;
        file << "                    \\ }{				" << std::endl;
        file << "                     }}{				" << std::endl;
        file << "                     }}{				" << std::endl;
        file << "                     {{}				" << std::endl;
        file << "               , -=-~{ .-^- _			" << std::endl;
        file << "                     `}				" << std::endl;
        file << "                      {				" << std::endl;
		file.close();
	}
}