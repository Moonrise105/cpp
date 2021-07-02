#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern i;
	Form *f;
	try {
		f = i.makeForm("Robotomy Request", "test1");
		f->action();
		delete f;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		f = i.makeForm("Presidential Pardon", "test2");
		f->action();
		delete f;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		f = i.makeForm("Shrubbery Creation", "test3");
		f->action();
		delete f;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	
    return (0);
}