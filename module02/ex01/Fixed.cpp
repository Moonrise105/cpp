#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->fixed = 0;
}

Fixed::Fixed(int const num) {
	std::cout << "Int constructor called\n";
	this->fixed = num << this->bits;
}

Fixed::Fixed(float const num) {
	std::cout << "Float constructor called\n";
	this->fixed = (int)roundf(num * (1 << this->bits));
}

float Fixed::toFloat(void) const {
	return ((float)this->fixed / (float)(1 << this->bits));
}

int Fixed::toInt(void) const {
	return (this->fixed >> this->bits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const &copy) {
	std::cout << "Copy constructor called\n";
	fixed = copy.getRawBits();
}

Fixed & Fixed::operator= (Fixed const &copy) {
	std::cout << "Assignation operator called\n";
	if (this != &copy)
		this->fixed = copy.getRawBits();
	return *this;	
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return this->fixed;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->fixed = raw;
}

std::ostream & operator<< (std::ostream& os, Fixed const &f) {
	os << f.toFloat();
	return os;
}
