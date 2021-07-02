#include "Brain.hpp"

Brain::Brain() {

};

Brain::~Brain() {
	
};

std::string Brain::identify(void) {
	std::stringstream ss;
	std::string str;
	
	ss << this;
	ss >> str;
	return str;
}

float const &Brain::getVolume(void) {
	return this->volume;
}
int const &Brain::getNeuronCount(void) {
	return this->neuron_count;
}

void Brain::setVolume(float &volume) {
	this->volume = volume;
}

void Brain::setNeuronCount(int &neuron_count) {
	this->neuron_count = neuron_count;
}
