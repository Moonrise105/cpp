#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character(std::string const & name);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		Character(Character const & copy);
		Character & operator=(Character & op);
	private:
		Character();
		std::string _name;
		AMateria *_inventory[4];
};

#endif