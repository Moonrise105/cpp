#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const & name) {
	std::cout << "Scav trap <" << name << "> created\n";
	this->name = name;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeDamage = 20;
	this->rangeDamage = 15;
	this->armorReduction = 3;
	srand(time(NULL));
}

ScavTrap::ScavTrap() {
	
}

ScavTrap::~ScavTrap() {
	std::cout << "Scav trap <" << name << "> destroyed\n";
}

ScavTrap::ScavTrap(ScavTrap const & scavTrap) {
	this->hitPoints = scavTrap.hitPoints;
	this->maxHitPoints = scavTrap.maxHitPoints;
	this->energyPoints = scavTrap.energyPoints;
	this->maxEnergyPoints = scavTrap.maxEnergyPoints;
	this->level = scavTrap.level;
	this->name = scavTrap.name;
	this->meleeDamage = scavTrap.meleeDamage;
	this->rangeDamage = scavTrap.rangeDamage;
	this->armorReduction = scavTrap.armorReduction;
	srand(time(NULL));
}

ScavTrap & ScavTrap::operator= (ScavTrap const & scavTrap) {
	if (this != &scavTrap) {
		this->hitPoints = scavTrap.hitPoints;
		this->maxHitPoints = scavTrap.maxHitPoints;
		this->energyPoints = scavTrap.energyPoints;
		this->maxEnergyPoints = scavTrap.maxEnergyPoints;
		this->level = scavTrap.level;
		this->name = scavTrap.name;
		this->meleeDamage = scavTrap.meleeDamage;
		this->rangeDamage = scavTrap.rangeDamage;
		this->armorReduction = scavTrap.armorReduction;
	}
	return *this;
}

std::string const & ScavTrap::getName(void) {
	return this->name;
}

unsigned int ScavTrap::getMeleeDamage(void) {
	return this->meleeDamage;
}

unsigned int ScavTrap::getRangeDamage(void) {
	return this->rangeDamage;
}

unsigned int ScavTrap::getHitPoints(void) {
	return this->hitPoints;
}

void ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "Scav trap <" << this->name << "> attacks <" <<
	target << "> at range, causing <" << this->rangeDamage <<
	"> points of damage!\n";
}

void ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "Scav trap <" << this->name << "> attacks <" <<
	target << "> at melee, causing <" << this->meleeDamage <<
	"> points of damage!\n";
}

void ScavTrap::takeDamage(unsigned int amount) {
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

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints + amount >= this->maxHitPoints) {
		this->hitPoints = this->maxHitPoints;
		std::cout << this->name << " completely healed\n";
	}
	else {
		this->hitPoints += amount;
		std::cout << "<" << this->name << "> healed <" << amount << "> points\n";
	}
}

void ScavTrap::challengeNewcomer(void) {
	if (this->energyPoints >= 25) {
		std::string challenges[5] = {
			"Did you try to open me?",
			"A single mag won't be enough!",
			"Let's get this party started!",
			"You call yourself a badass?",
			"Did someone feel something?"
		};
		std::cout << "<" << this->name << "> " << challenges[rand() % 5] << std::endl;
		this->energyPoints -= 25;
	}
	else {
		std::cout << "<" << this->name << "> dont have enough energy\n";
	}
}