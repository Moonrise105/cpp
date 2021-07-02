#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA {
	public:
		void attack(void);
		HumanA(std::string name, Weapon &weapon);
		void setWeapon(Weapon &weapon);
		~HumanA();
	private:
		std::string name;
		Weapon &weapon;
};
#endif
