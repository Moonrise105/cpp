#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	Form f1("test form", 5, 6);
	Bureaucrat b1("Bob", 10);
	Bureaucrat b2("John", 2);

	try {
		b1.signForm(f1);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << f1;
	
	try {
		b2.signForm(f1);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << f1;
	return 0;
}