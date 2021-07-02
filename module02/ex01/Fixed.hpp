#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed {
	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		~Fixed();							
		Fixed(Fixed const &copy);
		Fixed & operator= (Fixed const &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int fixed;
		static int const bits = 8;	
};

std::ostream & operator<< (std::ostream& os, Fixed const &f);
#endif
