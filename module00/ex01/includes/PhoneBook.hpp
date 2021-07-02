#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>
# include <iostream>
# include <stdlib.h>
# include "PhoneBook.hpp"
# include "utils.hpp"

class PhoneBook{


public:
	PhoneBook();
	~PhoneBook();
	void add_fields(Contact &contact);
	void add_contact(void);
	int search_contact(void);
	void print_fields(Contact &contact);
	void print_header();
	void print_contact(Contact &contact);
	void start(void);
	void wait_command(void);
	int get_command(void);
private:
	Contact contact_lst[8];
	int count;
	std::string names[11];
};
#endif
