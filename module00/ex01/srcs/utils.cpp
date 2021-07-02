#include "utils.hpp"

std::string int_to_str(int num) {
	std::stringstream ss;
	std::string str;

	ss << num;
	str = ss.str();
	return str;
}

bool		str_is_number(const std::string &str) {
	std::size_t i = 0;

	if (str[i] == '-') {
		++i;
	}
	for (; i < str.size(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
