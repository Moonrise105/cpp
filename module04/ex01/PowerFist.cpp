#include "PowerFist.hpp"

PowerFist::PowerFist() :
	AWeapon("Power Fist", 8, 50) {
	
}

PowerFist::~PowerFist() {

}

PowerFist & PowerFist::operator=(PowerFist const & op) {
	if (this != &op) {
		AWeapon::operator=(op);
	}
	return *this;
}

PowerFist::PowerFist(PowerFist const & copy) :
	AWeapon::AWeapon(copy) {

}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}