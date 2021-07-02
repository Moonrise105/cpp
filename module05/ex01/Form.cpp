#include "Bureaucrat.hpp"

const char* Form::FormAlreadySignedException::what() const throw() {
	return "Form already signed";
}

Form::Form(std::string const & name,
	int gradeSign, int gradeExec) :
		name_(name), sign_(true),
		gradeSign_(gradeSign), gradeExec_(gradeExec) {
	if (gradeSign < 1 || gradeExec_ < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (gradeSign > 150 || gradeExec_ > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->sign_ = false;
}

Form::Form(Form const & copy) :
	name_(copy.name_), sign_(copy.sign_), gradeSign_(copy.gradeSign_),
	gradeExec_(copy.gradeExec_) {

}

Form & Form::operator=(Form & op) {
	if (this != &op) {
		this->sign_ = op.sign_;
	}
	return *this;
}

Form::~Form() {}

std::string const & Form::getName() const {
	return this->name_;
}

bool Form::getSign() const {
	return this->sign_;
}

int Form::getGradeSign() const {
	return this->gradeSign_;
}

int Form::getGradeExec() const {
	return this->gradeExec_;
}

std::ostream & operator<<(std::ostream & os, Form & form) {
	os << "Form name: <" << form.getName() <<
		"> needs <" << form.getGradeSign() <<
		"> to sign and <" << form.getGradeExec() <<
		"> to execute. Now form is ";
	if (form.getSign()) {
		os << "signed";
	}
	else {
		os << "not signed";
	}
	os << std::endl;
	return os;
}

void Form::beSigned(Bureaucrat const & bur) {
	if (this->gradeSign_ < bur.getGrade()) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->sign_) {
		throw Form::FormAlreadySignedException();
	}
	else {
		this->sign_ = true;
	}
}
