#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	// Setup bureaucrats and forms
	try
	{
		ShrubberyCreationForm shrubbery("Home");
		RobotomyRequestForm robotomy("Teddy");
		PresidentialPardonForm pardon("Diddy");

		Bureaucrat rob("Rob", 135);
		Bureaucrat nico("Nico", 140);
		Bureaucrat cawley("Cawley", 45);
		Bureaucrat chuck("Chuck", 72);
		Bureaucrat donny("Donny", 1);
		Bureaucrat vance("Vance", 20);

		std::cout << rob << std::endl;
		std::cout << nico << std::endl;
		std::cout << cawley << std::endl;
		std::cout << chuck << std::endl;
		std::cout << donny << std::endl;
		std::cout << vance << std::endl;

		std::cout << std::endl;

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
		
}