#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

static void testForm(Bureaucrat* bur, Form* form)
{
    std::cout << std::endl << "Sign & Execute \033[33m" << form->getName() << "\033[0m : " << std::endl;
	try {
		bur->signForm(*form);
		
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		bur->executeForm(*form);
		
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
    ShrubberyCreationForm* shrub = new ShrubberyCreationForm("Patrick");
    RobotomyRequestForm* robot = new RobotomyRequestForm("Bob");
    PresidentialPardonForm* pardon = new PresidentialPardonForm("Pef");

    Bureaucrat* bob = new Bureaucrat("Bob", 120);
    Bureaucrat* james = new Bureaucrat("James", 33);
    Bureaucrat* meg = new Bureaucrat("Meg", 1);

    std::cout << "\033[31mNormal\033[0m tests : " << std::endl;

    testForm(bob, shrub);
    testForm(james, robot);
    testForm(meg, pardon);

    std::cout << std::endl << "\033[31mAlreadySigned & ToLow\033[0m tests : " << std::endl;

    testForm(bob, pardon);
	testForm(james, robot);

    delete shrub;
    delete robot;
    delete pardon;

    delete bob;
    delete james;
    delete meg;

    return (0);
}