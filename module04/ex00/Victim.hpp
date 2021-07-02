#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim {
	public:
		Victim();
		Victim(std::string const & name);	
		virtual ~Victim();
		Victim(Victim const & victim);
		Victim & operator= (Victim const & victim);
		std::string const & getName(void) const;
		void setName(std::string const & name);
		virtual void getPolymorphed() const;
	private:
		std::string name_;
		std::string title_;
};
std::ostream & operator<< (std::ostream & os, Victim const & victim);
#endif