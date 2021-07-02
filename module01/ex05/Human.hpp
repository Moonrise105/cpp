#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"

class Human {
	public:
		Human();
		~Human();
		Brain &getBrain(void);
		std::string identify(void);
	private:
		Brain *brain;
};
#endif