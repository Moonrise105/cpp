#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name) :
	ClapTrap(name, 100, 100, 100, 100,
		1, 30, 20, 5) {
	std::cout << "Frag trap created\n";
}

FragTrap::FragTrap() : ClapTrap() {

}

FragTrap::~FragTrap() {
	std::cout << "Frag trap destroyed\n";
}

FragTrap & FragTrap::operator= (FragTrap const & fragTrap) {
	if (this != &fragTrap)
		ClapTrap::operator=(fragTrap);
	return *this;
}

FragTrap::FragTrap(FragTrap const & fragTrap) : ClapTrap(fragTrap) {
	std::cout << "Frag trap copied\n";
}

void FragTrap::hook_attack(std::string const & target) {
	std::cout << "<" << this->getName() << "> hooked <" << target << 
	">. Chopper time !\n";
}

void FragTrap::sneak_attack(std::string const & target) {
	std::cout << "<" << this->getName() << "> conducted a stealth attack on <" << target << 
	">\n";
}

void FragTrap::verbal_attack(std::string const & target) {
	std::cout << "<" << this->getName() << "> humiliated <" << target << 
	">. <" << target << "> is crying ;(\n";
}

void FragTrap::self_attack(std::string const & target) {
	std::cout << "<" << this->getName() << "> attacked himself. <" << target << 
	"> laughs out loud :)\n";
}

void FragTrap::rocket_attack(std::string const & target) {
	std::cout << "<" << this->getName() << "> fired a rocket at <" << target << 
	">. BOOM!\n";
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->getEnergyPoints() >= 25) {
		void (FragTrap::*attacks[5])(std::string const &target) = {
		&FragTrap::hook_attack,
		&FragTrap::sneak_attack,
		&FragTrap::verbal_attack,
		&FragTrap::self_attack,
		&FragTrap::rocket_attack
		};
		(this->*attacks[rand() % 5])(target);
		this->setEnergyPoints(this->getEnergyPoints() - 25);
	}
	else {
		std::cout << this->getName() << " dont have enough energy\n";
	}
}

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << "<" << this->getName() << "> attacks <" <<
	target << "> at range, causing <" << this->getRangeDamage() <<
	"> points of damage!\n";
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << "<" << this->getName() << "> attacks <" <<
	target << "> at melee, causing <" << this->getMeleeDamage() <<
	"> points of damage!\n";
}
