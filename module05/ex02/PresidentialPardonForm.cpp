#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	Form("Presidential pardon form",
		25,
		5,
		target) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) :
	Form(copy) {
	
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm & form) {
	if (this != &form) {
		Form::operator=(form);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const {
	std::cout << this->getTarget() <<
		" has been pardoned by Zafod Beeblebrox" << std::endl;
}