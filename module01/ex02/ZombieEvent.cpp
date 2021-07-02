#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {
	this->type = "default";
}

ZombieEvent::~ZombieEvent() {

}

void ZombieEvent::setZombieType(std::string const &type) {
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	Zombie *zombie = new Zombie(name, this->type);
	return zombie;
}

Zombie* ZombieEvent::randomChump(std::string const *names, int count) {
	Zombie *z;
	int rand_index = std::rand() % count;
	z = this->newZombie(names[rand_index]);
	z->announce();
	return z;
}