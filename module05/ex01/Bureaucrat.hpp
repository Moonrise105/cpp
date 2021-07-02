#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Bureaucrat {
	private:
		std::string const name_;
		int grade_;
		Bureaucrat();
	public:
		std::string const & getName() const;
		int getGrade() const;
		Bureaucrat(std::string const &, int);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat & operator=(Bureaucrat &);
		virtual ~Bureaucrat();
		void incrementGrade();
		void dicrementGrade();
		void signForm(Form & form) const;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
std::ostream & operator<<(std::ostream &, Bureaucrat const &);
#endif