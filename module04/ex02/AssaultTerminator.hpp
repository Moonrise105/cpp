#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
	public:
		AssaultTerminator(AssaultTerminator const &);
		AssaultTerminator & operator=(AssaultTerminator &);
		AssaultTerminator * clone() const;
		AssaultTerminator();
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
		virtual ~AssaultTerminator();
};
#endif