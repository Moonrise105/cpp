#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
class ICharacter;

class AMateria {
	private:
		unsigned int _xp;
		std::string _type;
		AMateria();
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		AMateria & operator=(AMateria const & copy);
		virtual ~AMateria();
		std::string const & getType() const;
		unsigned int getXP() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		
};
#endif