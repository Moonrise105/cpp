#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form {
	private:
		std::string const name_;
		bool sign_;
		int const gradeSign_;
		int const gradeExec_;
		Form();
	public:
		Form(std::string const &, int, int);
		Form(Form const &);
		Form & operator=(Form &);
		virtual ~Form();
		std::string const & getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat const & bur);
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
std::ostream & operator<<(std::ostream &, Form &);
#endif