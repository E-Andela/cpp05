#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Intern intern;
		AForm *form1 = intern.makeForm("shrubbery creation", "home");
		AForm *form2 = intern.makeForm("robotomy request", "robot");
		AForm *form3 = intern.makeForm("presidential pardon", "president");

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}