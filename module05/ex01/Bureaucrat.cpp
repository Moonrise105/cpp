#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const & name, int grade) :
	name_(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->grade_ = grade;
	}
}

void Bureaucrat::signForm(Form & form) const {
	if (form.getSign()) {
		std::cout << this->name_ << " can not sign form because " <<
			form.getName() << " has already signed" << std::endl;
	}
	else if (form.getGradeSign() < this->grade_) {
		std::cout << this->name_ << " can not sign form because " <<
			"his grade is too low" << std::endl;
	}
	else {
		std::cout << this->name_ << " signs " << form.getName() <<
			std::endl;
	}
	form.beSigned(*this);
}

void Bureaucrat::incrementGrade() {
	if (this->grade_ <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		this->grade_ -= 1;
	}
}

void Bureaucrat::dicrementGrade() {
	if (this->grade_ >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->grade_ += 1;
	}
}

std::string const & Bureaucrat::getName() const {
	return this->name_;
}

int Bureaucrat::getGrade() const {
	return this->grade_;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) :
	name_(copy.name_), grade_(copy.grade_) {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat & op) {
	if (this != &op) {
		this->grade_ = op.grade_;
	}
	return *this;

}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & b) {
	os << "<" << b.getName() << ">, bureaucrat grade <" <<
		b.getGrade() << ">" << std::endl;
	return os;
}