#include "main.hpp"

const char* impossibleException::what() const throw() {
	return "impossible";
}

const char* nonDisplayableException::what() const throw() {
	return "Non displayable";
}

bool doubleIsInt(double num)
{
	return num == floor(num);
}

char convertToChar(double num) {
	int iNum;

	if (doubleIsInt(num)) {
		iNum = static_cast<int>(num);
		if (iNum > 31 && iNum < 128)
			return static_cast<char>(iNum);
		else if (iNum < 0 || iNum > 127)
			throw impossibleException();
		else {
			throw nonDisplayableException();
		}
	}
	else {
		throw impossibleException();
	}
}

void printChar(double num) {
	char c;
	try {
		c = convertToChar(num);
	}
	catch (impossibleException & e) {
		std::cout << e.what();
		return ;
	}
	catch (nonDisplayableException & e) {
		std::cout << e.what();
		return ;
	}
	std::cout << "\'" << c << "\'";
}

void printDouble(double num) {
	if (num - static_cast<int>(num) == static_cast<double>(0))
		std::cout << num << ".0";
	else
		std::cout << num;
}

void printFloat(float num) {
	if (num - static_cast<int>(num) == static_cast<float>(0))
		std::cout << num << ".0f";
	else
		std::cout << num << "f";
}

int convertToInt(double num) {
	if (num > std::numeric_limits<int>::max() ||
		num < std::numeric_limits<int>::min() ||
		num == std::numeric_limits<double>::infinity() ||
		num == -std::numeric_limits<double>::infinity() ||
		std::isnan(num)) {
			throw impossibleException();
		}
	else {
		return static_cast<int>(num);
	}

}

void printInt(double num) {
	int res;
	try {
		res = convertToInt(num);
	}
	catch (impossibleException & e) {
		std::cout << e.what();
		return ;
	}
	std::cout << res;
	
}

bool isSpecValue(char *str) {
	if (*str == '+' || *str == '-') {
		str++;
	}
	if ((!strcmp(str, "nan") || !strcmp(str, "inf") || !strcmp(str, "inff") ||
		!strcmp(str, "nanf")))
		return true;
	return false;
}

bool isNumeric(char *str) {
	if (*str == '+' || *str == '-')
		str++;
	while (*str) {
		if (*str == '.') {
			str++;
			break;
		}
		
		if (!isdigit(*str))
			return false;
		str++;
	}
	while (*str) {
		if (*str == 'f' && !str[1])
			return true;
		else if (!isdigit(*str))
			return false;
		str++;
	}
	return true;
}

bool isNumber(char *str) {
	if (isNumeric(str) || isSpecValue(str))
		return true;
	return false;
}

double strToDouble(char *str) {
	return atof(str);
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Wrong number of argumens" << std::endl;
		return 1;
	}
	else if (!av[1][0]) {
		std::cout << "Empty argument" << std::endl;
		return 1;
	}
	double d;
	if (isNumeric(av[1]) || isSpecValue(av[1])) {
		d = strToDouble(av[1]);
	}
	else if (strlen(av[1]) == 1) {
		d = static_cast<double>(av[1][0]);
	}
	else {
		std::cout << "char: impossible\n" <<
			"int: impossible\n" <<
			"float: impossible\n" <<
			"double: impossible\n";
		return 1;
	}

	std::cout << "char: ";
	printChar(d);
	std::cout << std::endl;

	std::cout << "int: ";
	printInt(d);
	std::cout << std::endl;

	std::cout << "float: ";
	printFloat(static_cast<float>(d));
	std::cout << std::endl;

	std::cout << "double: ";
	printDouble(d);
	std::cout << std::endl;
	
	return 0;
}