#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		RobotomyRequestForm & operator=(RobotomyRequestForm & op);
		virtual ~RobotomyRequestForm();
		virtual void action() const;
	private:
		RobotomyRequestForm();
};

#endif