#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include <iostream>
# include "Zombie.hpp"
# include <cstdlib>
# include <ctime>
# include <unistd.h>
class ZombieEvent {
	public:
		ZombieEvent();
		~ZombieEvent();
		void setZombieType(std::string const &type);
		Zombie* newZombie(std::string name); 
		Zombie* randomChump(std::string const *names, int count);
	private:
		std::string type;
};
#endif