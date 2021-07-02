#include "Zombie.hpp"

void Zombie::announce(void) const {
	std::cout << "<" << this->name << \
	" (" << this->type << ")> Braiiiiiiinnnssss...\n";
}

Zombie::~Zombie() {

}

Zombie::Zombie() {
	this->name = "defaultName";
	this->type = "defaultType";
}

Zombie::Zombie(std::string name, std::string type) {
	this->name = name;
	this->type = type;
}

void Zombie::setName(std::string const & name) {
	this->name = name;
}

void Zombie::setType(std::string const & type) {
	this->type = type;
}
