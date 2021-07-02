#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
	public:
		NinjaTrap(std::string const & name);
		virtual ~NinjaTrap();
		NinjaTrap(NinjaTrap const & ninjaTrap);
		NinjaTrap & operator= (NinjaTrap const & ninjaTrap);
		void ninjaShoebox(NinjaTrap & ninjaTrap);
		void ninjaShoebox(ScavTrap & scavTrap);
		void ninjaShoebox(FragTrap & fragTrap);
		void ninjaShoebox(ClapTrap & clapTrap);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
	protected:
		NinjaTrap();
};
#endif