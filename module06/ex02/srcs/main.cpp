#include "../includes/main.hpp"

Base * generate(void) {
	short rand = std::rand() % 3;
	switch (rand) {
		case 0:
			return static_cast<Base*>(new A);
		case 1:
			return static_cast<Base*>(new B);
		case 2:
			return static_cast<Base*>(new C);
	}
	return NULL;
}

void identify_from_pointer(Base * p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;

}

void identify_from_reference(Base & p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}


int main() {
	std::srand(std::time(NULL));
	Base *p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);
	
	return 0;
}