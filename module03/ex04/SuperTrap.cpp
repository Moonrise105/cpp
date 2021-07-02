#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const & name) : 
	ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5), 
	FragTrap(name), NinjaTrap(name) {
	std::cout << "Super trap created\n";
	srand(time(NULL));
	
}

SuperTrap::~SuperTrap() {
	std::cout << "Super trap destroyed\n";
}

SuperTrap::SuperTrap() : ClapTrap(),
	FragTrap(), NinjaTrap() {
}

SuperTrap & SuperTrap::operator= (SuperTrap const & superTrap) {
	if (this != &superTrap)
		ClapTrap::operator=(superTrap);
	return *this;
}

SuperTrap::SuperTrap(SuperTrap const & superTrap) : ClapTrap(superTrap) {
	std::cout << "Super trap copied\n";
	srand(time(NULL));
}

void SuperTrap::rangedAttack(std::string const & target) {
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) {
	NinjaTrap::meleeAttack(target);
}
