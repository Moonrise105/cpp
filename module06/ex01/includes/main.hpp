#ifndef MAIN_HPP
# define MAIN_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

typedef struct __attribute__ ((packed)) Data {
	std::string  p1;
	int num;
	std::string  p2;
} Data;

#endif