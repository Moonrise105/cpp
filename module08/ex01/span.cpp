#include "span.hpp"

Span::Span(unsigned int n) : storage_(), maxNums_(n) {
}

Span::~Span() {
	this->storage_.clear();
}

Span::Span(Span const & span) : storage_(span.storage_) {
	
}

Span & Span::operator= (Span & span) {
	if (this != &span) {
		this->storage_ = span.storage_;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (this->storage_.size() >= this->maxNums_) {
		throw SizeLimitException();
	}
	else {
		this->storage_.insert(num);
	}
}

const char* Span::SizeLimitException::what () const throw() {
	return "Size limit exception";
}

const char* Span::NoSpanException::what () const throw() {
	return "No span exception";
}

size_t Span::shortestSpan() {
	if (this->storage_.size() < 2) {
		throw NoSpanException();
	}
	std::multiset<int>::iterator p1 = this->storage_.begin();
	std::multiset<int>::iterator p2 = this->storage_.begin();
	p2++;
	size_t shortest = abs(*p2++ - *p1++);
	while (p2 != this->storage_.end()) {
		size_t diff = abs(*p2 - *p1);
		if (diff < shortest) {
			shortest = diff;
		}
		p1++;
		p2++;
	}
	return shortest;
}

size_t Span::longestSpan() {
	if (this->storage_.size() < 2) {
		throw NoSpanException();
	}
	size_t diff = *this->storage_.rbegin() - *this->storage_.begin();
	return diff;
}