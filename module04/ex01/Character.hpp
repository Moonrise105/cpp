#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {
	private:
		std::string name_;
		int actionPoints_;
		AWeapon * weapon_;
		Character();
	public:
		Character(std::string const & name);
		Character(Character const & copy);
		Character & operator=(Character const & op);
		virtual ~Character();
		void recoverAP();
		void equip(AWeapon *);
		void attack(Enemy *);
		std::string const & getName() const;
		AWeapon const * getWeapon() const;
		int getActionPoints() const;
};
std::ostream & operator<<(std::ostream & os,
	Character const & character);
#endif