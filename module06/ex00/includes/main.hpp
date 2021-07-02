#ifndef MAIN_HPP
# define MAIN_HPP
# include <iostream>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <iomanip>
# include <limits>
# include <stdio.h>

class impossibleException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class nonDisplayableException : public std::exception {
	public:
		virtual const char* what() const throw();
};
#endif