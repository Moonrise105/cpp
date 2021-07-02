#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer(std::string const & name, std::string const & title);	
		virtual ~Sorcerer();
		Sorcerer(Sorcerer const & sorcerer);
		Sorcerer & operator= (Sorcerer const & sorcerer);
		std::string const & getName(void) const;
		std::string const & getTitle(void) const;
		void setName(std::string const & name);
		void setTitle(std::string const & name);
		void polymorph(Victim const &) const;
	private:
		Sorcerer();
		std::string name_;
		std::string title_;
};
std::ostream & operator<< (std::ostream & os, Sorcerer const & sorcerer);
#endif