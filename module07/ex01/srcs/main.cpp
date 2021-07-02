# include "iter.hpp"

template<typename T>
void f(T &a) {
	std::cout << a << std::endl;
}

int main() {
	float arrFloat[3] = {1.5, 2.5, 3.5};
	iter(arrFloat, static_cast<size_t>(3), f);

	int arrInt[4] = {1, 2, 3, 4};
	iter(arrInt, static_cast<size_t>(4), f);
	return 0;
}