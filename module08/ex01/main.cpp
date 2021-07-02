#include "span.hpp"

int main() {
	std::srand(time(NULL));
	Span sp = Span(10000);
	std::vector<int> v(10000);
	std::vector<int>::iterator begin = v.begin();
	std::vector<int>::iterator end = v.end();
	while (begin != end) {
		*begin = std::rand() - 1000000000;
		begin++;
	}
	begin = v.begin();
	sp.addNumber(begin, end);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
