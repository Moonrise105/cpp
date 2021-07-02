#include "easyfind.hpp"

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	std::vector<int>::iterator it_v;
	it_v = easyfind(v, 2);
	std::cout << *it_v << std::endl;

	std::list<int> l;
	l.push_back(2);
	l.push_back(7);
	std::list<int>::iterator it_l;
	it_l = easyfind(l, 7);
	std::cout << *it_l << std::endl;

	try {
		it_l = easyfind(l, 99);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
