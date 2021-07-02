#ifndef SPAN_HPP
#define SPAN_HPP
# include <vector>
# include <iostream>
# include <set>
# include <ctime>
# include <unistd.h>
# include <cstdlib>

class Span {
	private:
		std::multiset<int> storage_;
		unsigned int maxNums_;
	public:
		class SizeLimitException : public std::exception {
			virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception {
			virtual const char* what() const throw();
		};
		Span(unsigned int n);
		virtual ~Span();
		Span(Span const & span);
		Span & operator= (Span & span);
		void addNumber(int num);
		size_t shortestSpan();
		size_t longestSpan();
		template <class Iter>
		void addNumber(Iter & begin, Iter & end) {
			while (begin != end) {
				this->addNumber(*begin);
				begin++;
			}
			
		}
		

};

#endif /* SPAN_HPP */
