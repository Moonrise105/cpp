#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
	Zombie z1("Bob", "Fat");
	

	z1.announce();
	ZombieEvent ze;
	ze.setZombieType("Fast");
	std::string *names = new std::string [5];
	names[0] = "Bob";
	names[1] = "Jack";
	names[2] = "Alexandra";
	names[3] = "Ivan";
	names[4] = "Dima";
	std::srand(std::time(nullptr));
	Zombie *z2;
	Zombie *z3;
	Zombie *z4;
	Zombie *z5;
	z2 = ze.randomChump(names, 5);
	z3 = ze.randomChump(names, 5);
	z4 = ze.randomChump(names, 5);
	z5= ze.randomChump(names, 5);
	delete z2;
	delete z3;
	delete z4;
	delete z5;
	delete[] names;
	return 0;
}