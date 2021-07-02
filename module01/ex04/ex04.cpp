#include <iostream>
#include <string>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *pointer = &str;
	std::string &reference = str;

	std::cout << *pointer << "\n";
	std::cout << reference << "\n";
	return 0;
}
