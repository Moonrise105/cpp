#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon {
	private:
		std::string name_;
		int damage_;
		int actionPoints_;
		AWeapon();
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & copy);
		AWeapon & operator=(AWeapon const & op);
		virtual ~AWeapon();
		std::string const & getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
};
# endif