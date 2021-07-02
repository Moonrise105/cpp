#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony {
	public:
		Pony();
		Pony(int weight, int length, int age, std::string name);
		~Pony();
		void setWeight(int weight);
		void setLength(int length);
		void setAge(int age);
		void setName(std::string name);
		int const & getWeight(void);
		int const & getLength(void);
		int const & getAge(void);
		std::string const & getName(void);
		void say_age(void);

	private:
		int weight;
		int length;
		int age;
		std::string name;
};
#endif