#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string const & name);
		virtual ~FragTrap();
		FragTrap(FragTrap const & fragTrap);
		FragTrap & operator= (FragTrap const & fragTrap);
		void vaulthunter_dot_exe(std::string const & target);
		void hook_attack(std::string const & target);
		void sneak_attack(std::string const & target);
		void verbal_attack(std::string const & target);
		void self_attack(std::string const & target);
		void rocket_attack(std::string const & target);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
	protected:
		FragTrap();
};
#endif
