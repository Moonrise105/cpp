#include "Cure.hpp"

Cure::Cure() : AMateria::AMateria("cure") {

}

Cure::~Cure() {

}

Cure & Cure::operator=(Cure &copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}

Cure::Cure(Cure const & copy) : AMateria::AMateria(copy) {
	
}

AMateria * Cure::clone() const {
	return new Cure;
}

void Cure::use(ICharacter & target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() <<
	"'s wounds *" << std::endl;
}