#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB {
	public:
		void attack(void);
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		~HumanB();
	private:
		std::string name;
		Weapon *weapon;
};
#endif
