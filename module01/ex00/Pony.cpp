#include "Pony.hpp"

void Pony::setWeight(int weight) {
	this->weight = weight;
}

void Pony::setLength(int length) {
	this->length = length;
}

void Pony::setAge(int age) {
	this->age = age;
}

void Pony::setName(std::string name) {
	this->name = name;
}

int const & Pony::getWeight(void) {
	return this->weight;
}

int const & Pony::getLength(void) {
	return this->length;
}

int const & Pony::getAge(void) {
	return this->age;
}

std::string const & Pony::getName(void) {
	return this->name;
}

Pony::Pony() {
	this->weight = 0;
	this->length = 0;
	this->age = 0;
	this->name = "";
}

Pony::Pony(int weight, int length, int age, std::string name) {
	this->weight = weight;
	this->length = length;
	this->age = age;
	this->name = name;
}

Pony::~Pony() {

}

void Pony::say_age(void) {
	std::cout << this->getName() << " say:\n";
	if (this->age >= 60) {
		std::cout << "...";
	}
	else {
		for (int i = 0; i < this->age; i++) {
			std::cout << "igogo!\n";
		}
	}
}