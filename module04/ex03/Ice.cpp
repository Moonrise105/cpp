#include "Ice.hpp"

Ice::Ice() : AMateria::AMateria("ice") {

}

Ice::~Ice() {

}

Ice & Ice::operator=(Ice &copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}

Ice::Ice(Ice const & copy) : AMateria::AMateria(copy) {
	
}

AMateria * Ice::clone() const {
	return new Ice;
}

void Ice::use(ICharacter & target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() <<
	" *" << std::endl;
}