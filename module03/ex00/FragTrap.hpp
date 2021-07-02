#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class FragTrap {
	public:
		virtual ~FragTrap();
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & fragTrap);
		FragTrap & operator= (FragTrap const & fragTrap);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);
		void hook_attack(std::string const & target);
		void sneak_attack(std::string const & target);
		void verbal_attack(std::string const & target);
		void self_attack(std::string const & target);
		void rocket_attack(std::string const & target);
		std::string const & getName(void);
		unsigned int getMeleeDamage(void);
		unsigned int getRangeDamage(void);
		unsigned int getHitPoints(void);

	private:
		FragTrap();
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