#include "../inc/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name {"Default"}, _grade {150}
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name {name}, _grade {grade}
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called for " << _name << " with a grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name {other._name}, _grade {other._grade}
{
	std::cout << "Bureaucrat copy constructor called for " << _name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// _name is const, so we cannot assign to it
		_grade = other._grade;
	}
	std::cout << "Bureaucrat assignment operator called for " << _name << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " << _name << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << _name << " incremented to grade " << _grade << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << _name << " decremented to grade " << _grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}
const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}