#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
	#ifdef DEBUG
	std::cout << "Intern default constructor called" << std::endl;
	#endif
}

Intern::Intern(const Intern &other)
{
	#ifdef DEBUG
	std::cout << "Intern copy constructor called" << std::endl;
	#endif
	(void)other; // Avoid unused parameter warning
}

Intern& Intern::operator=(const Intern &other)
{
	#ifdef DEBUG
	std::cout << "Intern assignment operator called" << std::endl;
	#endif
	(void)other; // Avoid unused parameter warning
	return *this; // Assignment operator should return *this
}

Intern::~Intern(void)
{
	#ifdef DEBUG
	std::cout << "Intern destructor called" << std::endl;
	#endif
}

static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
static AForm* createPresidential(const std::string& target) {return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	AForm* (*creator[])(const std::string&) = {createShrubbery, createRobotomy, createPresidential};
	std::string compareStrings[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (size_t i = 0; i < sizeof(creator) / sizeof(creator[0]); ++i)
	{
		if (formName == compareStrings[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creator[i](target);
		}
	}
	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const noexcept
{
	return "Unknown form type";
}