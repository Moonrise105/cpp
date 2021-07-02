#include "Pony.hpp"

void ponyOnTheHeap(void) {
	Pony *p1 = new Pony(40, 100, 10, "Applejack");

	p1->say_age();
	delete p1;
}

void ponyOnTheStack(void) {
	Pony p1(50, 120, 20, "Fluttershy");

	p1.say_age();
}

int		main(void) {
	ponyOnTheStack();
	ponyOnTheHeap();
	return 0;
}