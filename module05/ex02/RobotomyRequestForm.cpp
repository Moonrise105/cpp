#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	Form("Robotomy request form",
		72,
		45,
		target) {
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) :
	Form(copy) {
	
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm & form) {
	if (this != &form) {
		Form::operator=(form);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
	std::cout << "vrrrrrr vrrrrr vrrrrr..." << std::endl;
	if (std::rand() % 2) {
		std::cout << this->getTarget() << " has robotomized successfully" << std::endl;
	}
	else {
		std::cout << this->getTarget() << " has not robotomized" << std::endl;
	}
	
}