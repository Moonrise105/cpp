#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const & name) :
	ClapTrap(name, 60, 60, 120, 120, 
		1, 60, 5, 0) {
	std::cout << "Ninja trap created\n";
	srand(time(NULL));
}

NinjaTrap & NinjaTrap::operator= (NinjaTrap const & ninjaTrap) {
	if (this != &ninjaTrap)
		ClapTrap::operator=(ninjaTrap);
	return *this;
}

NinjaTrap::NinjaTrap(NinjaTrap const & ninjaTrap) : ClapTrap(ninjaTrap) {
	std::cout << "Ninja trap copied\n";
	srand(time(NULL));
}

NinjaTrap::NinjaTrap() {

}

NinjaTrap::~NinjaTrap() {
	std::cout << "Ninja trap destroyed\n";
}

void NinjaTrap::ninjaShoebox(NinjaTrap & ninjaTrap) {
	std::cout << "<" << this->getName() << 
		"> stealthily attacked ninja trap <" <<
		ninjaTrap.getName() << ">" << std::endl; 
}

void NinjaTrap::ninjaShoebox(ScavTrap & scavTrap) {
	std::cout << "<" << this->getName() << 
		"> stealthily attacked scav trap <" <<
		scavTrap.getName() << ">" << std::endl; 
}

void NinjaTrap::ninjaShoebox(FragTrap & fragTrap) {
	std::cout << "<" << this->getName() << 
		"> stealthily attacked frag trap <" <<
		fragTrap.getName() << ">" << std::endl; 
}

void NinjaTrap::ninjaShoebox(ClapTrap & clapTrap) {
	std::cout << "<" << this->getName() << 
		"> stealthily attacked clap trap <" <<
		clapTrap.getName() << ">" << std::endl; 
}

void NinjaTrap::rangedAttack(std::string const & target) {
	std::cout << "<" << this->getName() << "> attacks <" <<
	target << "> at range, causing <" << this->getRangeDamage() <<
	"> points of damage!\n";
}

void NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << "<" << this->getName() << "> attacks <" <<
	target << "> at melee, causing <" << this->getMeleeDamage() <<
	"> points of damage!\n";
}
