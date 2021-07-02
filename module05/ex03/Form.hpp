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
		std::string target_;
		Form();
	public:
		Form(std::string const &, int, int, std::string const & target);
		Form(Form const &);
		Form & operator=(Form &);
		virtual ~Form();
		std::string const & getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;
		std::string const & getTarget() const;
		void beSigned(Bureaucrat const & bur);
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
std::ostream & operator<<(std::ostream &, Form &);
#endif