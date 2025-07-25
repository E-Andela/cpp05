#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45)
	, _target {"default"}
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other)
	, _target {other._target}
{
	std::cout << "RobotomyRequestForm copy constructor called for form with target " << other._target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45)
	, _target {target}
{
	std::cout << "RobotomyRequestForm constructor called with target " << target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
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
		std::cout << executor.getName() << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy on " << executor.getName() << " has failed" << std::endl;
}