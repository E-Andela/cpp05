#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool 				_signed;
	const int 			_signGrade;
	const int 			_execGrade;

public:
	Form(void);
	Form(const Form &other);
	Form(const std::string &name, int signGrade, int execGrade);

	Form &operator=(const Form &other) = delete;

	~Form();

	void beSigned(const Bureaucrat &signer);

	const std::string& getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif