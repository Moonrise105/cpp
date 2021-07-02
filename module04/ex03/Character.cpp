#include "Character.hpp"

Character::Character(std::string const & name) :
	_name(name) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria * m) {
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == m) {
			return ;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3 && this->_inventory[idx]) {
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter & target) {
	if (idx >= 0 && idx <= 3 && this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
	}
}

Character::Character(Character const & copy) {
	this->_name = copy._name;
	for (int i = 0; i < 4; ++i) {
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
}

Character & Character::operator=(Character & op) {
	if (this != &op) {
		for (int i = 0; i < 4; ++i) {
			if (this->_inventory[i]) {
				delete this->_inventory[i];
			}
		}
		this->_name = op._name;
		for (int i = 0; i < 4; ++i) {
			if (op._inventory[i]) {
				this->_inventory[i] = op._inventory[i]->clone();
			}
		}
	}
	
	return *this;
}
