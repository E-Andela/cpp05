#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45)
	, _target {"default"}
{
	#ifdef DEBUG
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other)
	, _target {other._target}
{
	#ifdef DEBUG
	std::cout << "RobotomyRequestForm copy constructor called for form with target " << other._target << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45)
	, _target {target}
{
	#ifdef DEBUG
	std::cout << "RobotomyRequestForm constructor called with target " << target << std::endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	#endif
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::executeAction(const Bureaucrat &executor) const
{
	std::srand(time(NULL));
	int rand = std::rand();

	const char* drillingNoises[] = {
		"BZZZZZZ",
		"WHIRRRRR",
		"RRRRRRR",
		"DUG-DUG-DUG-DUG",
		"BRRRRRRRT",
		"KRRR-KRRR-KRRR",
		"GRRRRRNK",
		"GRNK-GRNK",
		"SCRRRRREEEE",
		"RRRNNNNNNN",
		"CHNK-CHNK",
		"SKRRRT",
		"CHRRRRRK"
	};

	std::cout << drillingNoises[std::rand() % 13] << std::endl;;

	if (rand % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " has failed" << std::endl;
	(void)executor; // Avoid unused parameter warning
}