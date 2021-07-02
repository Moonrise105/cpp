#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replace(std::string &all, std::string const &s1, std::string const &s2) {
	std::size_t pos = 0;

	while (1) {
		pos =  all.find(s1, pos);
		if (pos == std::string::npos) {
			break;
		}
		else {
			all.replace(pos, s1.size(), s2);
		}
		++pos;
	}	
}

int main(int ac, char **av) {
	std::ifstream file;
	std::ofstream file_replace;
	std::stringstream ss;
	std::string str;

	if (ac != 4) {
		std::cerr << "Invalid number of arguments\n";
		return 1;
	}
	if (!av[2][0] || !av[3][0])
	{
		std::cerr << "Empty string error\n";
		return 1;
	}
	file.open(av[1]);
	if (!file) {
		std::cerr << "Open file error\n";
		return 1;
	}
	ss << file.rdbuf();
	str = ss.str();
	file.close();
	if (!file) {
		std::cerr << "Close file error\n";
		return 1;
	}
	replace(str, std::string(av[2]), std::string(av[3]));
	std::string name = std::string(av[1]) + ".replace";
	file_replace.open(name.c_str());
	if (!file_replace) {
		std::cerr << "Open file error\n";
		return 1;
	}
	file_replace.write(str.c_str(), str.size());
	file_replace.close();
	if (!file_replace) {
		std::cerr << "Close file error\n";
		return 1;
	}
	return 0;
}
