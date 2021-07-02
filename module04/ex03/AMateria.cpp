#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _xp(0),_type(type) {

}

AMateria::~AMateria() {
	
}

AMateria::AMateria(AMateria const & copy) {
	this->_type = copy._type;
	this->_xp = copy._xp;
}

AMateria & AMateria::operator=(AMateria const & copy) {
	if (this != &copy) {
		this->_type = copy._type;
		this->_xp = copy._xp;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

unsigned int AMateria::getXP() const {
	return this->_xp;
}

void AMateria::use(ICharacter &) {
	this->_xp += 10;
}


