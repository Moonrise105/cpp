#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include <string>
# include <stdlib.h>
# include <time.h>

class SuperTrap : public FragTrap, public NinjaTrap {
	public:
		SuperTrap(std::string const & name);
		virtual ~SuperTrap();
		SuperTrap(SuperTrap const & superTrap);
		SuperTrap & operator= (SuperTrap const & superTrap);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
	protected:
		SuperTrap();
};
#endif