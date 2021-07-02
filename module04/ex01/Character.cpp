#include "Character.hpp"

Character::Character(std::string const & name) :
	name_(name), actionPoints_(40) {
}

Character::~Character() {

}

Character::Character(Character const & copy) {
	this->name_ = copy.name_;
	this->actionPoints_ = copy.actionPoints_;
	this->weapon_ = copy.weapon_;
}

Character & Character::operator=(Character const & op) {
	if (this != &op) {
		this->name_ = op.name_;
		this->actionPoints_ = op.actionPoints_;
		this->weapon_ = op.weapon_;
	}
	return *this;
}

void Character::recoverAP() {
	if (this->actionPoints_ + 10 >= 40)
		this->actionPoints_ = 40;
	else {
		this->actionPoints_ += 10;
	}
}

void Character::equip(AWeapon * weapon) {
	this->weapon_ = weapon;
}

void Character::attack(Enemy * enemy) {
	if (this->actionPoints_ < this->weapon_->getAPCost()) {
		std::cout << "Not enough action points" << std::endl;
	}
	else if (!enemy) {
		std::cout << "Enemy is dead" << std::endl;
	}
	else {
		this->actionPoints_ -= this->weapon_->getAPCost();
		std::cout << this->name_ << " attacks " << enemy->getType() <<
		" with a " << this->weapon_->getName() << std::endl;
		this->weapon_->attack();
		enemy->takeDamage(this->weapon_->getDamage());
		if (enemy->getHP() <= 0) {
			delete enemy;
		}
	}
}

AWeapon const * Character::getWeapon() const {
	return this->weapon_;
}

int Character::getActionPoints() const {
	return this->actionPoints_;
}

std::string const & Character::getName() const {
	return this->name_;
}

std::ostream & operator<<(std::ostream & os,
	Character const & character) {
	AWeapon const *weapon = character.getWeapon();

	std::cout << character.getName() << " has " <<
		character.getActionPoints() << " and ";
	if (weapon) {
		std::cout << "wields a " << weapon->getName() << std::endl;
	}
	else {
		std::cout << "is unarmed" << std::endl;
	}
	return os;
}
