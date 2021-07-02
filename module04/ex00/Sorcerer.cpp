#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : name_("defaultName"), title_("defaultTitle") {
	std::cout << this->name_ << ", " << this->title_ <<
	", is born!\n";	
}

Sorcerer::Sorcerer(std::string const & name, std::string const & title) :
		name_(name), title_(title) {
	std::cout << this->name_ << ", " << this->title_ <<
	", is born!\n";	
}

Sorcerer::~Sorcerer() {
	std::cout << this->name_ << ", " << this->title_ <<
	", is dead. Consequences will never be the same!\n";
}

Sorcerer::Sorcerer(Sorcerer const & sorcerer) {
	this->name_ = sorcerer.name_;
	this->title_ = sorcerer.title_;
}

Sorcerer & Sorcerer::operator= (Sorcerer const & sorcerer) {
	if (this != &sorcerer) {
		this->name_ = sorcerer.name_;
		this->title_ = sorcerer.title_;
	}
	return *this;
}

std::string const & Sorcerer::getName(void) const {
	return this->name_;
}

std::string const & Sorcerer::getTitle(void) const {
	return this->title_;
}

void Sorcerer::setName(std::string const & name) {
	this->name_ = name;
}

void Sorcerer::setTitle(std::string const & title) {
	this->title_ = title;
}

void Sorcerer::polymorph(Victim const & victim) const {
	victim.getPolymorphed();
}

std::ostream & operator<< (std::ostream & os,
		Sorcerer const & sorcerer) {
	os << "I am " << sorcerer.getName() << ", " <<
	sorcerer.getTitle() << ", and I like ponies!\n";
	return os;
}