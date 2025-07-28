#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <stdexcept>
#include "../inc/AForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &other);
	
	Intern &operator=(const Intern &other);
	
	~Intern(void);

	AForm* makeForm(const std::string &formName, const std::string &target) const;

	class UnknownFormException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};
};

#endif