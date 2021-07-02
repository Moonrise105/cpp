#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include "utils.hpp"

class Contact {


public:
	Contact();
	Contact(int);
	
	~Contact();

	void	setFirstName(const std::string &first_name);
	void	setLastName(const std::string &last_name);
	void	setNickname(const std::string &nickname);
	void	setLogin(const std::string &login);
	void	setPostalAddress(const std::string &postal_address);
	void	setEmail(const std::string &email);
	void	setPhoneNumber(const std::string &phone_number);
	void	setBirthday(const std::string &birthday);
	void	setMeal(const std::string &meal);
	void	setColor(const std::string &color);
	void	setSecret(const std::string &secret);

	const std::string	&getFirstName();
	const std::string	&getLastName();
	const std::string	&getNickname();
	const std::string	&getLogin();
	const std::string	&getPostalAddress();
	const std::string	&getEmail();
	const std::string	&getPhoneNumber();
	const std::string	&getBirthday();
	const std::string	&getMeal();
	const std::string	&getColor();
	const std::string	&getSecret();
	const int			&getIndex();

private:
	int			index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email;
	std::string phone_number;
	std::string birthday;
	std::string meal;
	std::string color;
	std::string secret;
	
};
#endif
