#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>
# include <stdlib.h>
# include <time.h>

class ClapTrap {
	public:
		virtual ~ClapTrap();
		ClapTrap(std::string const & name, 
			unsigned int hitPoints, 
			unsigned int maxHitPoints,
			unsigned int energyPoints,
			unsigned int maxEnergyPoints,
			unsigned int level,
			unsigned int meleeDamage,
			unsigned int rangeDamage,
			unsigned int armorReduction);
		ClapTrap & operator= (ClapTrap const & clapTrap);
		ClapTrap(ClapTrap const & clapTrap);
		unsigned int getMeleeDamage(void);
		unsigned int getRangeDamage(void);
		unsigned int getHitPoints(void);
		unsigned int getEnergyPoints(void);
		void setEnergyPoints(unsigned int const & energyPoints);
		std::string const & getName(void);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		unsigned int hitPoints;
		unsigned int maxHitPoints;
		unsigned int energyPoints;
		unsigned int maxEnergyPoints;
		unsigned int level;
		std::string name;
		unsigned int meleeDamage;
		unsigned int rangeDamage;
		unsigned int armorReduction;
	protected:
		ClapTrap();
};

		

	
		
#endif