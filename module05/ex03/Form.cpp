#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::FormAlreadySignedException::what() const throw() {
	return "Form already signed";
}

const char* Form::FormNotSignedException::what() const throw() {
	return "Form not signed";
}

Form::Form(std::string const & name,
	int gradeSign, int gradeExec, std::string const & target) :
		name_(name), sign_(true),
		gradeSign_(gradeSign), gradeExec_(gradeExec),
		target_(target) {
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
		"> to execute. Target is " << form.getTarget() <<
		". Now form is ";
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
	if (this->sign_) {
		throw Form::FormAlreadySignedException();
	}
	else if (this->gradeSign_ < bur.getGrade()) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->sign_ = true;
	}
}

std::string const & Form::getTarget() const {
	return this->target_;
}

void Form::execute(Bureaucrat const & executor) const {
	if (!this->sign_) {
		std::cout << this->name_ << " is not signed" << std::endl;
		throw Form::FormNotSignedException();
	}
	else if (this->gradeExec_ < executor.getGrade()) {
		std::cout << executor.getName() << " grade is too low" <<
			std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->action();
	}
}