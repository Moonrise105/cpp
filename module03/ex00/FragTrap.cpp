#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name) {
	std::cout << "Frag trap <" << name << "> created\n";
	this->name = name;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeDamage = 30;
	this->rangeDamage = 20;
	this->armorReduction = 5;
	srand(time(NULL));
}

FragTrap::FragTrap() {
	
}

FragTrap::~FragTrap() {
	std::cout << "Frag trap <" << name << "> destroyed\n";
}

FragTrap::FragTrap(FragTrap const & fragTrap) {
	this->hitPoints = fragTrap.hitPoints;
	this->maxHitPoints = fragTrap.maxHitPoints;
	this->energyPoints = fragTrap.energyPoints;
	this->maxEnergyPoints = fragTrap.maxEnergyPoints;
	this->level = fragTrap.level;
	this->name = fragTrap.name;
	this->meleeDamage = fragTrap.meleeDamage;
	this->rangeDamage = fragTrap.rangeDamage;
	this->armorReduction = fragTrap.armorReduction;
	srand(time(NULL));
}

FragTrap & FragTrap::operator= (FragTrap const & fragTrap) {
	if (this != &fragTrap) {
		this->hitPoints = fragTrap.hitPoints;
		this->maxHitPoints = fragTrap.maxHitPoints;
		this->energyPoints = fragTrap.energyPoints;
		this->maxEnergyPoints = fragTrap.maxEnergyPoints;
		this->level = fragTrap.level;
		this->name = fragTrap.name;
		this->meleeDamage = fragTrap.meleeDamage;
		this->rangeDamage = fragTrap.rangeDamage;
		this->armorReduction = fragTrap.armorReduction;
	}
	return *this;
}

std::string const & FragTrap::getName(void) {
	return this->name;
}

unsigned int FragTrap::getMeleeDamage(void) {
	return this->meleeDamage;
}

unsigned int FragTrap::getRangeDamage(void) {
	return this->rangeDamage;
}

unsigned int FragTrap::getHitPoints(void) {
	return this->hitPoints;
}

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP <" << this->name << "> attacks <" <<
	target << "> at range, causing <" << this->rangeDamage <<
	"> points of damage!\n";
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP <" << this->name << "> attacks <" <<
	target << "> at melee, causing <" << this->meleeDamage <<
	"> points of damage!\n";
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints + this->armorReduction <= amount) {
		this->hitPoints = 0;
		std::cout << "<" << this->name << "> got fatal damage\n";
	}
	else if (this->armorReduction >= amount) {
		std::cout << "<" << this->name << "> absorbed all damage\n";
	}
	else {
		this->hitPoints = this->hitPoints + this->armorReduction - amount;
		std::cout << "<" << this->name << "> got <" << 
		amount - (int)this->armorReduction << "> pure damage, absorbed <" << 
		this->armorReduction << "> damage\n";
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints + amount >= this->maxHitPoints) {
		this->hitPoints = this->maxHitPoints;
		std::cout << this->name << " completely healed\n";
	}
	else {
		this->hitPoints += amount;
		std::cout << "<" << this->name << "> healed <" << amount << "> points\n";
	}
}

void FragTrap::hook_attack(std::string const & target) {
	std::cout << "<" << this->name << "> hooked <" << target << 
	">. Chopper time !\n";
}

void FragTrap::sneak_attack(std::string const & target) {
	std::cout << "<" << this->name << "> conducted a stealth attack on <" << target << 
	">\n";
}

void FragTrap::verbal_attack(std::string const & target) {
	std::cout << "<" << this->name << "> humiliated <" << target << 
	">. <" << target << "> is crying ;(\n";
}

void FragTrap::self_attack(std::string const & target) {
	std::cout << "<" << this->name << "> attacked himself. <" << target << 
	"> laughs out loud :)\n";
}

void FragTrap::rocket_attack(std::string const & target) {
	std::cout << "<" << this->name << "> fired a rocket at <" << target << 
	">. BOOM!\n";
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->energyPoints >= 25) {
		void (FragTrap::*attacks[5])(std::string const &target) = {
		&FragTrap::hook_attack,
		&FragTrap::sneak_attack,
		&FragTrap::verbal_attack,
		&FragTrap::self_attack,
		&FragTrap::rocket_attack
		};
		(this->*attacks[rand() % 5])(target);
		this->energyPoints -= 25;
	}
	else {
		std::cout << "<" << this->name << "> dont have enough energy\n";
	}
}