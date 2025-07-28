#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool 				_signed;
	const int 			_signGrade;
	const int 			_execGrade;

public:
	AForm(void);
	AForm(const AForm &other);
	AForm(const std::string &name, int signGrade, int execGrade);

	AForm &operator=(const AForm &other) = delete;

	virtual ~AForm();

	void beSigned(const Bureaucrat &signer);
	void execute(const Bureaucrat &executor) const;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

protected:
	virtual void executeAction(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif