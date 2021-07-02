#include "AWeapon.hpp"

std::string const & AWeapon::getName() const {
	return this->name_;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) {
	this->name_ = name;
	this->actionPoints_ = apcost;
	this->damage_ = damage;
}

int AWeapon::getAPCost() const {
	return this->actionPoints_;
}

int AWeapon::getDamage() const {
	return this->damage_;
}

AWeapon::~AWeapon() {
}

AWeapon::AWeapon(AWeapon const & copy) {
	this->damage_ = copy.damage_;
	this->actionPoints_ = copy.actionPoints_;
	this->name_ = copy.name_;
}

AWeapon & AWeapon::operator=(AWeapon const & op) {
	if (this != &op) {
		this->name_ = op.name_;
		this->actionPoints_ = op.actionPoints_;
		this->damage_ = op.damage_;
	}
	return *this;
}