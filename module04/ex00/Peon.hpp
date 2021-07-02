#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>
# include "Victim.hpp"

class Peon : public Victim {
	public:
		Peon();
		Peon(std::string const & name);	
		virtual ~Peon();
		Peon(Peon const & peon);
		Peon & operator= (Peon const &peon);
		virtual void getPolymorphed() const;
};

#endif