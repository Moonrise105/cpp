#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria{
	public:
		Ice();
		virtual ~Ice();
		Ice & operator=(Ice &);
		Ice(Ice const &);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif