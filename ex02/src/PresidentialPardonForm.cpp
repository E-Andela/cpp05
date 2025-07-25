#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5)
	, _target {"default"}
{
	#ifdef DEBUG
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other)
	, _target {other._target}
{
	#ifdef DEBUG
	std::cout << "PresidentialPardonForm copy constructor called for form with target " << other._target << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5)
	, _target {target}
{
	#ifdef DEBUG
	std::cout << "PresidentialPardonForm constructor called with target " << target << std::endl;
	#endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	#endif
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::executeAction(const Bureaucrat &executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}