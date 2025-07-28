#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/tests.hpp"
#include <iostream>

int main()
{	
	std::srand(time(NULL));
	
	testVarietyForms();
	std::cout << "----------------------------------------" << std::endl;
	testFailSigning();
	std::cout << "----------------------------------------" << std::endl;
	testFailExecuting();
	std::cout << "----------------------------------------" << std::endl;
	testExecutingShrubbery();
	std::cout << "----------------------------------------" << std::endl;
	testExecutingRobotomy();
	std::cout << "----------------------------------------" << std::endl;
	testExecutingPardon();
	return 0;
}