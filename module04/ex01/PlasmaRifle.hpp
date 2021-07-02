#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		PlasmaRifle & operator=(PlasmaRifle const & op);
		PlasmaRifle(PlasmaRifle const & copy);
		virtual ~PlasmaRifle();
		virtual void attack() const;
};
#endif