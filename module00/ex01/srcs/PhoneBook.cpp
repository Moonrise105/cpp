#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->count = 0;
	this->names[0] = "first name";
	this->names[1] = "last name";
	this->names[2] = "nickname";
	this->names[3] = "login";
	this->names[4] = "postal address";
	this->names[5] = "email";
	this->names[6] = "phone number";
	this->names[7] = "birthday date";
	this->names[8] = "favorite meal";
	this->names[9] = "underwear color";
	this->names[10] = "secret";
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add_fields(Contact &contact) {
	std::string buf;

	for (int i = 0; i < 11; i++)
	{
		std::cout << "Enter " << this->names[i] << ": ";
		std::getline(std::cin, buf);
		switch (i)
		{
		case 0:
			contact.setFirstName(buf);
			break;
		case 1:
			contact.setLastName(buf);
			break;
		case 2:
			contact.setNickname(buf);
			break;
		case 3:
			contact.setLogin(buf);
			break;
		case 4:
			contact.setPostalAddress(buf);
			break;
		case 5:
			contact.setEmail(buf);
			break;
		case 6:
			contact.setPhoneNumber(buf);
			break;
		case 7:
			contact.setBirthday(buf);
			break;
		case 8:
			contact.setMeal(buf);
			break;
		case 9:
			contact.setColor(buf);
			break;
		case 10:
			contact.setSecret(buf);
			break;
		}
	}
}

void PhoneBook::add_contact(void) {
	if (this->count < 8) {
		this->contact_lst[this->count] = Contact(this->count);
		this->add_fields(this->contact_lst[this->count]);
		this->count++;
	}
	else {
		std::cout << "You cannot add more than 8 contacts\n";
	}
}

void PhoneBook::print_fields(Contact &contact) {
	std::string out;

	for (int i = 0; i < 4; i++) {
		switch (i)
		{
		case 0:
			out = int_to_str(contact.getIndex());
			break;
		case 1:
			out = contact.getFirstName();
			break;
		case 2:
			out = contact.getLastName();
			break;
		case 3:
			out = contact.getNickname();
			break;
		}
		if (out.size() >= 10) {
			out = out.substr(0, 10).replace(9, 1, ".");
		}
		std::cout.width(10); std::cout << std::right <<  out << '|';
	}
	std::cout << '\n';
	
}

void PhoneBook::print_contact(Contact &contact) {
	for (int i = 0; i < 11; i++) {
		std::cout << this->names[i] << ": ";
		switch (i)
		{
		case 0:
			std::cout << contact.getFirstName() << "\n";
			break;
		case 1:
			std::cout << contact.getLastName() << "\n";
			break;
		case 2:
			std::cout << contact.getNickname() << "\n";
			break;
		case 3:
			std::cout << contact.getLogin() << "\n";
			break;
		case 4:
			std::cout << contact.getPostalAddress() << "\n";
			break;
		case 5:
			std::cout << contact.getEmail() << "\n";
			break;
		case 6:
			std::cout << contact.getPhoneNumber() << "\n";
			break;
		case 7:
			std::cout << contact.getBirthday() << "\n";
			break;
		case 8:
			std::cout << contact.getMeal() << "\n";
			break;
		case 9:
			std::cout << contact.getColor() << "\n";
			break;
		case 10:
			std::cout << contact.getSecret() << "\n";
			break;
		}
	}
}

void PhoneBook::print_header() {
	std::string out;

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			out = "index";
		}
		else {
			out = this->names[i - 1];
		}
		if (out.size() >= 10) {
			out = out.substr(0, 10).replace(9, 1, ".");
		}
		std::cout.width(10); std::cout << std::right <<  out << '|';
	}
	std::cout << '\n';
	for (int j = 0; j < 44; j++) {
		std::cout << '-';
	}
	std::cout << "\n";
}

int PhoneBook::search_contact(void) {
	int code = 0;

	this->print_header();
	for (int i = 0; i < this->count; i++) {
		this->print_fields(this->contact_lst[i]);
	}
	if (this->count > 0) {
		std::string num;
		int nbr;
		
		code = 1;
		std::cout << "Enter index from 0 to " \
		<< this->count - 1 << " to get full information: ";
		std::cin >> num;
		if (str_is_number(num)) {
			nbr = atoi(num.c_str());
			if (nbr >= 0 && nbr < this->count) {
				print_contact(this->contact_lst[nbr]);
			}
			else {
				std::cout << "Index not in range\n";
			}
		}
		else {
			std::cout << "Index not a number\n";
		}
	}
	return code;
}

int PhoneBook::get_command(void) {
	std::string command;

	std::cout << "phonebook$ ";
	std::getline(std::cin, command);
	if (command == "ADD") {
		this->add_contact();
	}
	else if (command == "SEARCH") {
		if (this->search_contact() == 1) {
			std::getline(std::cin, command);
		}
	}
	else if (command == "EXIT"){
		return (1);
	}
	else {
		std::cout << "Unknown command. Use next commands: ADD | SEARCH | EXIT\n";
	}
	return (0);
}

void PhoneBook::start(void) {
	std::cout << "Enter command. ADD | SEARCH | EXIT\n";
	while (1) {

		if (get_command() == 1) {
			break ;
		}
	}
}
