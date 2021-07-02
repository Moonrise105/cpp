#include "SuperMutant.hpp"

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & copy) : 
	Enemy::Enemy(copy){
}

SuperMutant & SuperMutant::operator=(SuperMutant const & op) {
	if (this != &op) {
		Enemy::operator=(op);
	}
	return *this;
}

void SuperMutant::takeDamage(int damage) {
	if (damage > 0) {
		setHP(getHP() - damage - 3);
		if (getHP() < 0)
			setHP(0);
	}
}