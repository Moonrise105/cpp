#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("Bob", 160);
		std::cout << b;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		Bureaucrat b("Bob", 0);
		std::cout << b;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bob", 50);
		std::cout << b;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bob", 150);
		b.dicrementGrade();
		std::cout << b;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bob", 1);
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bob", 50);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.dicrementGrade();
		std::cout << b;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}