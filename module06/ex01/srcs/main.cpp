#include "../includes/main.hpp"

void * serialize(void) {
	Data * data = new Data;
	std::srand(std::time(NULL));
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz" \
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ""1234567890";
	int s1_len = std::rand() % 50 + 5;
	int s2_len = std::rand() % 50 + 5;
	data->p1.reserve(s1_len);
	data->p2.reserve(s2_len);
	for (int i = 0; i < s1_len; ++i) {
		data->p1 += alphabet[std::rand() % alphabet.length()];
	}
	for (int i = 0; i < s2_len; ++i) {
		data->p2 += alphabet[std::rand() % alphabet.length()];
	}
	data->num = std::rand() % 10000 - 5000;
	return reinterpret_cast<void*>(data);
}

Data * deserialize(void * raw) {
	return reinterpret_cast<Data*>(raw);
}

int main(void) {
	void * v = serialize();
	Data * p = deserialize(v);
	std::cout << p->p1 << std::endl;
	std::cout << p->p2 << std::endl;
	std::cout << p->num << std::endl;
	delete p;
	return 0;
}