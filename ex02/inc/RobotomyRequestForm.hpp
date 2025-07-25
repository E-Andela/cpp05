#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "../inc/AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm(const std::string &target);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other) = delete;

	~RobotomyRequestForm() override;

	const std::string& getTarget() const;

protected:
	virtual void executeAction(const Bureaucrat &executor) const override;

};

#endif