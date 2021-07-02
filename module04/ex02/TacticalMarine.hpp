#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
	public:
		TacticalMarine(TacticalMarine const &);
		TacticalMarine & operator=(TacticalMarine &);
		TacticalMarine * clone() const;
		TacticalMarine();
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
		virtual ~TacticalMarine();
};
#endif