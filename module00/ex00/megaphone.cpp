#include <iostream>
#include <ctype.h>
#include <string>


int		main(int ac, char **av)
{

	std::string arg;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		arg = av[i];
		for (int j = 0; j < arg.size(); j++)
			std::cout << (char)std::toupper(arg[j]);
	}
	std::cout << "\n";
	return (0);
}