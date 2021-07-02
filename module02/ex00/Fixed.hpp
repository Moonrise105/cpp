#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed & operator= (Fixed const &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int fixed;
		static int const bits = 8;	
};
#endif
