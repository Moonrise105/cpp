#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"
# include <iostream>

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		PresidentialPardonForm & operator=(PresidentialPardonForm & op);
		virtual ~PresidentialPardonForm();
		virtual void action() const;
	private:
		PresidentialPardonForm();
};

#endif