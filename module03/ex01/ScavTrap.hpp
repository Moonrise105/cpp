#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class ScavTrap {
	public:
		virtual ~ScavTrap();
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & scavTrap);
		ScavTrap & operator= (ScavTrap const & scavTrap);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(void);
		std::string const & getName(void);
		unsigned int getMeleeDamage(void);
		unsigned int getRangeDamage(void);
		unsigned int getHitPoints(void);

	private:
		ScavTrap();
		unsigned int hitPoints;
		unsigned int maxHitPoints;
		unsigned int energyPoints;
		unsigned int maxEnergyPoints;
		unsigned int level;
		std::string name;
		unsigned int meleeDamage;
		unsigned int rangeDamage;
		unsigned int armorReduction;
		
};
#endif