#include "../inc/Form.hpp"
#include <iostream>
#include "../inc/Bureaucrat.hpp"

Form::Form(void)
	: _name {"default"}
	, _signed {false}
	, _signGrade {1}
	, _execGrade {1}
{
	#ifdef DEBUG
	std::cout << "Form default constructor called" << std::endl;
	#endif
}

Form::Form(const Form &other) 
	: _name {other._name}
	, _signed {other._signed}
	, _signGrade {other._signGrade}
	, _execGrade {other._execGrade}
{
	#ifdef DEBUG
	std::cout << "Form copy constructor called for " << _name << std::endl;
	#endif
}

Form::Form(const std::string &name, int signGrade, int execGrade)
	: _name {name}
	, _signed {false}
	, _signGrade {signGrade}
	, _execGrade {execGrade}
{
	if (signGrade > 150 || execGrade > 150)
	throw GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
	throw GradeTooHighException();
	#ifdef DEBUG
	std::cout << "Form constructor called for " << _name << std::endl;
	#endif
}

Form::~Form()
{
	#ifdef DEBUG
	std::cout << "Form destructor called for " << _name << std::endl;
	#endif
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() <= _signGrade)
	{
		_signed = true;
		std::cout << signer.getName() << " signed " << _name << std::endl;
	}
	else
	{
		std::cerr << signer.getName() << " couldn't sign " << _name << " because his grade is too low" << std::endl;
		throw GradeTooLowException();
	}
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << " needs grade " << form.getSignGrade()
		<< " to be signed and " << form.getExecGrade() << " to be executed. ";
	if (form.getSigned())
		os << "Form is signed.";
	else
		os << "Form is not yet signed";
	
	return os;
}