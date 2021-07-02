#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap destroyed\n";
}

ClapTrap::ClapTrap(std::string const & name, 
		unsigned int hitPoints, 
		unsigned int maxHitPoints,
		unsigned int energyPoints,
		unsigned int maxEnergyPoints,
		unsigned int level,
		unsigned int meleeDamage,
		unsigned int rangeDamage,
		unsigned int armorReduction
	) :
		hitPoints(hitPoints),
		maxHitPoints(maxHitPoints),
		energyPoints(energyPoints),
		maxEnergyPoints(maxEnergyPoints),
		level(level),
		name(name),
		meleeDamage(meleeDamage),
		rangeDamage(rangeDamage),
		armorReduction(armorReduction) {
	std::cout << "Claptrap created\n";
	srand(time(NULL));
	}

ClapTrap::ClapTrap(ClapTrap const & clapTrap) {
	this->hitPoints = clapTrap.hitPoints;
	this->maxHitPoints = clapTrap.maxHitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->maxEnergyPoints = clapTrap.maxEnergyPoints;
	this->level = clapTrap.level;
	this->name = clapTrap.name;
	this->meleeDamage = clapTrap.meleeDamage;
	this->rangeDamage = clapTrap.rangeDamage;
	this->armorReduction = clapTrap.armorReduction;
	std::cout << "Clap trap copied\n";
	srand(time(NULL));
}

ClapTrap & ClapTrap::operator= (ClapTrap const & clapTrap) {
	if (this != &clapTrap) {
		this->hitPoints = clapTrap.hitPoints;
		this->maxHitPoints = clapTrap.maxHitPoints;
		this->energyPoints = clapTrap.energyPoints;
		this->maxEnergyPoints = clapTrap.maxEnergyPoints;
		this->level = clapTrap.level;
		this->name = clapTrap.name;
		this->meleeDamage = clapTrap.meleeDamage;
		this->rangeDamage = clapTrap.rangeDamage;
		this->armorReduction = clapTrap.armorReduction;
	}
	return *this;
}

void ClapTrap::setEnergyPoints(unsigned int const & energyPoints) {
	this->energyPoints = energyPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) {
	return this->energyPoints;
}

std::string const & ClapTrap::getName(void) {
	return this->name;
}

unsigned int ClapTrap::getMeleeDamage(void) {
	return this->meleeDamage;
}

unsigned int ClapTrap::getRangeDamage(void) {
	return this->rangeDamage;
}

unsigned int ClapTrap::getHitPoints(void) {
	return this->hitPoints;
}

void ClapTrap::takeDamage(unsigned int amount) {
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

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints + amount >= this->maxHitPoints) {
		this->hitPoints = this->maxHitPoints;
		std::cout << this->name << " completely healed\n";
	}
	else {
		this->hitPoints += amount;
		std::cout << "<" << this->name << "> healed <" << amount << "> points\n";
	}
}
