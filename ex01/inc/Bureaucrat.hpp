#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include "../inc/Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

	
	public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	
	Bureaucrat &operator=(const Bureaucrat &other) = delete;
	
	~Bureaucrat();

	void signForm(Form &form);
	
	const std::string &getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif