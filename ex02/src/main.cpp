#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		PresidentialPardonForm form("home");
		Bureaucrat max("Max", 1);

		max.signForm(form);
		form.execute(max);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}