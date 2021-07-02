#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include "Enemy.hpp"

class SuperMutant : public Enemy {
	public:
		SuperMutant();
		virtual ~SuperMutant();
		SuperMutant(SuperMutant const & copy);
		SuperMutant & operator=(SuperMutant const & op);
		virtual void takeDamage(int);	
};

#endif