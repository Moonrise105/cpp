#include "Human.hpp"

Human::Human() {
	Brain brain;
	this->brain = &brain;
};

Human::~Human() {

};

Brain &Human::getBrain(void) {
	return *this->brain;	
};

std::string Human::identify(void) {
	return this->brain->identify();
}