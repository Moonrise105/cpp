#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>

class Intern;

typedef struct s_pair {
			std::string name;
			Form* (Intern::*create)(std::string const & target);
		} t_pair;

class Intern {
	public:
				
		Intern();
		Intern(Intern const &);
		Intern & operator=(Intern &);
		virtual ~Intern();
		Form * createPresidential(std::string const & target);
		Form * createRobotomy(std::string const & target);
		Form * createShrubbery(std::string const & target);
		Form * makeForm(std::string const & formName,
			std::string const & target);
		class FormNotExist : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		t_pair *funcs;
};

#endif