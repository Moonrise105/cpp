#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string const & name);
		virtual ~ScavTrap();
		ScavTrap(ScavTrap const & scavTrap);
		ScavTrap & operator= (ScavTrap const & scavTrap);
		void challengeNewcomer(void);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
	protected:
		ScavTrap();
};
#endif