# include "Array.hpp"

int main() {
	unsigned int sizeInt = 3;
	std::cout << std::right << std::setfill('_') << std::setw(20) <<  "ARRAY INT" << std::endl;
	Array<int> arr(sizeInt);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	for (unsigned int i = 0; i < sizeInt; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "size = " <<  arr.size() << std::endl;

	std::cout << std::right << std::setfill('_') << std::setw(20) <<  "COPY" << std::endl;
	Array<int> arrNew(arr);
	arr[0] = 4;
	for (unsigned int i = 0; i < sizeInt; ++i) {
		std::cout << arrNew[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "size = " <<  arr.size() << std::endl;
	
	std::cout << std::right << std::setfill('_') << std::setw(20) <<  "ASSIGMENT" << std::endl;
	arrNew = arr;
	for (unsigned int i = 0; i < sizeInt; ++i) {
		std::cout << arrNew[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "size = " <<  arr.size() << std::endl;

	unsigned int sizeFloat = 4;
	std::cout << std::right << std::setfill('_') << std::setw(20) <<  "ARRAY FLOAT" << std::endl;
	Array<float> arrF(sizeFloat);
	arrF[0] = 1.5f;
	arrF[1] = 2.6f;
	arrF[2] = 3.2f;
	arrF[3] = 0.5f;
	for (unsigned int i = 0; i < sizeFloat; ++i) {
		std::cout << arrF[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "size = " <<  arrF.size() << std::endl;
	
	try {
		std::cout << arrF[4] << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}