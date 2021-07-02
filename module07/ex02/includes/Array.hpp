#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <iomanip>

template<class T>
class Array {
	private:
		T * array_;
		unsigned int size_;
	public:
		Array() {
			this->array_ = new T[0];
			this->size_ = 0;
			this->array_[0] = 0;
		};
		Array(unsigned int n) {
			this->array_ = new T[n];
			this->size_ = n;
			for (unsigned int i = 0; i < this->size_; ++i) {
				array_[i] = 0;
			}
		}
		virtual ~Array() {
			delete [] this->array_;
		}
		Array(Array const & copy) {
			this->array_ = new T[copy.size_];
			this->size_ = copy.size_;
			for (unsigned int i = 0; i < this->size_; ++i) {
				array_[i] = copy.array_[i];
			}
		}
		Array & operator=(Array & op) {
			if (this != &op) {
				delete [] this->array_;
				this->array_ = new T[op.size_];
				this->size_ = op.size_;
				for (unsigned int i = 0; i < this->size_; ++i) {
					array_[i] = op.array_[i];
				}
			}
			return *this;
		}

		T & operator[] (const unsigned int index) {
			if (size_ == 0 || index > (this->size_ - 1)) {
				throw std::exception();
			}
			return this->array_[index];
		}

		T const & operator[] (const unsigned int index) const {
			if (index > (this->size_ - 1)) {
				throw std::exception();
			}
			return this->array_[index];
		}

		unsigned int size() const {
			return this->size_;
		}

		
};

#endif /* ARRAY_HPP */
