#include "RadScorpion.hpp"

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & copy) : 
	Enemy::Enemy(copy){
}

RadScorpion & RadScorpion::operator=(RadScorpion const & op) {
	if (this != &op) {
		Enemy::operator=(op);
	}
	return *this;
}
