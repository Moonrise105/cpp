#include "Peon.hpp"

Peon::Peon() : Victim() {
	std::cout << "Zog zog.\n";
}

Peon::Peon(std::string const & name) : Victim(name) {
	std::cout << "Zog zog.\n";
}

Peon::~Peon() {
	std::cout << "Bleuark...\n";
}

Peon::Peon(Peon const & peon) : Victim(peon) {

}

Peon & Peon::operator= (Peon const &peon) {
	if (this != &peon)
		Victim::operator=(peon);
	return *this;
}

void Peon::getPolymorphed() const {
	std::cout << this->getName() << " has been turned into a pink pony!\n";
}