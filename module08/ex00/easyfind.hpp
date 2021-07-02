#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class NotFoundException : public std::exception {
	virtual const char* what() const throw() {
		return "Not found";
	}
};

template <template <class, class> class Container>
typename Container<int, std::allocator<int> >::iterator
	easyfind(Container<int, std::allocator<int> > & cont, int num) {
	typename Container<int, std::allocator<int> >::iterator it;
	if ((it = std::find(cont.begin(), cont.end(), num)) != cont.end()) {
		return it;	
	}
	throw NotFoundException();
}
#endif /* EASYFIND_HPP */
