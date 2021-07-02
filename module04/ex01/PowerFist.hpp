#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
	public:
		PowerFist();
		PowerFist & operator=(PowerFist const & op);
		PowerFist(PowerFist const & copy);
		virtual ~PowerFist();
		virtual void attack() const;
};
#endif