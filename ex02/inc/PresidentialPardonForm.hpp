#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "../inc/AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm(const std::string &target);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other) = delete;

	~PresidentialPardonForm() override;

	const std::string& getTarget() const;

protected:
	virtual void executeAction(const Bureaucrat &executor) const override;

};

#endif