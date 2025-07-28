#include "../inc/AForm.hpp"
#include <iostream>
#include "../inc/Bureaucrat.hpp"

AForm::AForm(void)
	: _name {"default"}
	, _signed {false}
	, _signGrade {1}
	, _execGrade {1}
{
	#ifdef DEBUG
	std::cout << "Form default constructor called" << std::endl;
	#endif
}

AForm::AForm(const AForm &other) 
	: _name {other._name}
	, _signed {other._signed}
	, _signGrade {other._signGrade}
	, _execGrade {other._execGrade}
{
	#ifdef DEBUG
	std::cout << "Form copy constructor called for " << _name << std::endl;
	#endif
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	: _name {name}
	, _signed {false}
	, _signGrade {signGrade}
	, _execGrade {execGrade}
{
	#ifdef DEBUG
	std::cout << "Form constructor called for " << _name << std::endl;
	#endif
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
	#ifdef DEBUG
	std::cout << "Form destructor called for " << _name << std::endl;
	#endif
}

void AForm::beSigned(const Bureaucrat &signer)
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

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
	{
		std::cerr << executor.getName() << " couldn't execute " << _name
			<< " because it's not signed" << std::endl;
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _execGrade)
	{
		std::cerr << executor.getName() << " couldn't execute " << _name
			<< " because his grade is too low" << std::endl;
		throw GradeTooLowException();
	}
	std::cout << executor.getName() << " executes " << _name << std::endl;
	executeAction(executor);
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.getName() << " needs grade " << form.getSignGrade()
		<< " to be signed and " << form.getExecGrade() << " to be executed. ";
	if (form.getSigned())
		os << "Form is signed.";
	else
		os << "Form is not yet signed";
	
	return os;
}