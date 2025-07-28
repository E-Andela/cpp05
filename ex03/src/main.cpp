#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/tests.hpp"
#include <iostream>

int main(void)
{
	testCreatingInvalidForm();
	std::cout << "----------------------------------------" << std::endl;
	testIntern();

	return 0;
}