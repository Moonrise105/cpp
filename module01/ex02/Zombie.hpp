#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name, std::string type);
		~Zombie();
		void announce(void) const;
		void setName(std::string const & name);
		void setType(std::string const & type);

	private:
		std::string name;
		std::string type;
};
#endif