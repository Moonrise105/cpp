#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :
	AWeapon("Plasma Rifle", 5, 21) {
	
}

PlasmaRifle::~PlasmaRifle() {

}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & op) {
	if (this != &op) {
		AWeapon::operator=(op);
	}
	return *this;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & copy) :
	AWeapon::AWeapon(copy) {

}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}