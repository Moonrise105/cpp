#include "Contact.hpp"

Contact::Contact() {

}

Contact::Contact(int index) {
	this->index = index;
}

Contact::~Contact() {
}

const std::string &Contact::getFirstName() {
	return this->first_name;
}

const std::string &Contact::getLastName() {
	return this->last_name;
}

const std::string &Contact::getNickname() {
	return this->nickname;
}

const std::string &Contact::getLogin() {
	return this->login;
}

const std::string &Contact::getPostalAddress() {
	return this->postal_address;
}

const std::string &Contact::getEmail() {
	return this->email;
}

const std::string &Contact::getPhoneNumber() {
	return this->phone_number;
}

const std::string &Contact::getBirthday() {
	return this->birthday;
}

const std::string &Contact::getMeal() {
	return this->meal;
}

const std::string &Contact::getColor() {
	return this->color;
}

const std::string &Contact::getSecret() {
	return this->secret;
}

const int 			&Contact::getIndex() {
	return this->index;
}

void	Contact::setFirstName(const std::string &first_name) {
	this->first_name = first_name;
}

void	Contact::setLastName(const std::string &last_name) {
	this->last_name = last_name;
}

void	Contact::setNickname(const std::string &nickname) {
	this->nickname = nickname;
}

void	Contact::setLogin(const std::string &login) {
	this->login = login;
}

void	Contact::setPostalAddress(const std::string &postal_address) {
	this->postal_address = postal_address;
}

void	Contact::setEmail(const std::string &email) {
	this->email = email;
}

void	Contact::setPhoneNumber(const std::string &phone_number) {
	this->phone_number = phone_number;
}

void	Contact::setBirthday(const std::string &birthday) {
	this->birthday = birthday;
}

void	Contact::setMeal(const std::string &meal) {
	this->meal = meal;
}

void	Contact::setColor(const std::string &color) {
	this->color = color;
}

void	Contact::setSecret(const std::string &secret) {
	this->secret = secret;
}
