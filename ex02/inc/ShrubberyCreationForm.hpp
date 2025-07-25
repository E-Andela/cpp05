#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "../inc/AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const std::string &target);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = delete;

	~ShrubberyCreationForm() override;

	const std::string& getTarget() const;

protected:
	virtual void executeAction(const Bureaucrat &executor) const override;
};

#endif