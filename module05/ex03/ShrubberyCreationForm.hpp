#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm & op);
		virtual ~ShrubberyCreationForm();
		virtual void action() const;
	private:
		ShrubberyCreationForm();
};

#endif