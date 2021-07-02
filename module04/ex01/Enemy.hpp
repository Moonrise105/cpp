#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy {
	private:
		int hp;
		std::string type;
		Enemy();
	public:
		Enemy(Enemy const &copy);
		Enemy & operator=(Enemy const & op);
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		std::string const & getType() const;
		int getHP() const;
		void setHP(int hp);
		void setType(std::string const & type);
		virtual void takeDamage(int);

};
#endif