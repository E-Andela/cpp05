#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "../inc/Bureaucrat.hpp"

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

	Form &operator=(const Form &other);

	~Form();

	void beSigned(const Bureaucrat &signer);

	const std::string& getName();
	bool getSigned();
	const int getSignGrade();
	const int getExecGrade();

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

#endif