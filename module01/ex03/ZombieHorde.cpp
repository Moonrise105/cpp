#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {
	if (n <= 0)
		n = 1;
	std::string names[5] = {
	"Bob",
	"Jack",
	"Alexandra",
	"Ivan",
	"Dima"
	};
	std::srand(std::time(nullptr));

	this->zombies = new Zombie[n];
	this->zombieCount = n;
	for (int i = 0; i < n; i++) {
		this->zombies[i].setName(names[std::rand() % 5]);
	}
}

ZombieHorde::~ZombieHorde() {
	delete[] this->zombies;
}

void ZombieHorde::announce(void) const {
	for (int i = 0; i < this->zombieCount; i++) {
		this->zombies[i].announce();
	}
}