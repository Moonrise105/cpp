#include "ScavTrap.hpp"



ScavTrap::ScavTrap(std::string const & name) :
	ClapTrap(name, 100, 100, 50, 50, 
		1, 20, 15, 3) {
	std::cout << "Scav trap created\n";
}

ScavTrap & ScavTrap::operator= (ScavTrap const & scavTrap) {
	if (this != &scavTrap)
		ClapTrap::operator=(scavTrap);
	return *this;
}

ScavTrap::ScavTrap(ScavTrap const & scavTrap) : ClapTrap(scavTrap) {
	std::cout << "Scav trap copied\n";
}

ScavTrap::ScavTrap() {

}

ScavTrap::~ScavTrap() {
	std::cout << "Scav trap destroyed\n";
}

void ScavTrap::challengeNewcomer(void) {
	if (this->getEnergyPoints() >= 25) {
		std::string challenges[5] = {
			"Did you try to open me?",
			"A single mag won't be enough!",
			"Let's get this party started!",
			"You call yourself a badass?",
			"Did someone feel something?"
		};
		std::cout << "<" << this->getName() << "> " << challenges[rand() % 5] << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 25);
	}
	else {
		std::cout << "<" << this->getName() << "> dont have enough energy\n";
	}
}

void ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "<" << this->getName() << "> attacks <" <<
	target << "> at range, causing <" << this->getRangeDamage() <<
	"> points of damage!\n";
}

void ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "<" << this->getName() << "> attacks <" <<
	target << "> at melee, causing <" << this->getMeleeDamage() <<
	"> points of damage!\n";
}
