#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
	this->name = name;
}

HumanA::~HumanA() {

}

void HumanA::attack(void) {
	std::cout << this->name <<
	" attacks with " << this->weapon.getType() << "\n";
}

void HumanA::setWeapon(Weapon &weapon) {
	this->weapon = weapon;
}
