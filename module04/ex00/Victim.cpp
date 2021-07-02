#include "Victim.hpp"

Victim::Victim() : name_("defaultName") {
	std::cout << "Some random victim called " << this->name_ <<
	" just appeared!\n";
}

Victim::Victim(std::string const & name) :
		name_(name) {
	std::cout << "Some random victim called " << this->name_ <<
	" just appeared!\n";	
}

Victim::~Victim() {
	std::cout << "Victim " << this->name_ <<
	" just died for no apparent reason!\n";
}

Victim::Victim(Victim const & victim) {
	this->name_ = victim.name_;
	this->title_ = victim.title_;
}

Victim & Victim::operator= (Victim const & victim) {
	if (this != &victim) {
		this->name_ = victim.name_;
		this->title_ = victim.title_;
	}
	return *this;
}

std::string const & Victim::getName(void) const {
	return this->name_;
}

void Victim::setName(std::string const & name) {
	this->name_ = name;
}

void Victim::getPolymorphed() const {
	std::cout << this->name_ <<
	" has been turned into a cute little sheep!\n";
}

std::ostream & operator<< (std::ostream & os,
		Victim const & victim) {
	os << "I 'm " << victim.getName() << " and I like otters!\n";
	return os;
}