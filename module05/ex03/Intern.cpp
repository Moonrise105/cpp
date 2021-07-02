#include "Intern.hpp"

const char* Intern::FormNotExist::what() const throw() {
	return "Form does not exist";
}

Form * Intern::createPresidential(std::string const & target) {
	return new PresidentialPardonForm(target);
}

Form * Intern::createRobotomy(std::string const & target) {
	return new RobotomyRequestForm(target);
}

Form * Intern::createShrubbery(std::string const & target) {
	return new ShrubberyCreationForm(target);
}

Intern::Intern() {
	this->funcs = new t_pair[3];
	this->funcs[0].name = "Presidential Pardon";
	this->funcs[0].create =  &Intern::createPresidential;
	this->funcs[1].name = "Robotomy Request";
	this->funcs[1].create =  &Intern::createRobotomy;
	this->funcs[2].name = "Shrubbery Creation";
	this->funcs[2].create = &Intern::createShrubbery;
}

Intern::~Intern() {
	delete [] this->funcs;
}

Intern::Intern(Intern const &) {}

Intern & Intern::operator=(Intern &) {
	return *this;
}



Form * Intern::makeForm(std::string const & formName,
	std::string const & target) {
	for (int i = 0; i < 3; ++i) {
		if (formName == this->funcs[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*(this->funcs[i].create))(target);
		}
	}
	std::cout << "Intern can not create " << formName << std::endl;
	throw Intern::FormNotExist();
	return NULL;

}