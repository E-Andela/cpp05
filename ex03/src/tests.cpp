#include "../inc/tests.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

#include <iostream>

void testVarietyForms()
{
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

		std::cout	<< shrubbery << std::endl
					<< robotomy << std::endl
					<< pardon << std::endl;

		std::cout << std::endl;

		std::cout	<< rob << std::endl
					<< nico << std::endl
					<< cawley << std::endl
					<< chuck << std::endl
					<< donny << std::endl
					<< vance << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testFailSigning()
{
	try
	{
		ShrubberyCreationForm shrubbery("Home");
		Bureaucrat nico("Nico", 150);

		nico.signForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}		
}

void testFailExecuting()
{
	try
	{
		ShrubberyCreationForm shrubbery("Home");
		Bureaucrat rob("Rob", 138);

		rob.signForm(shrubbery);
		rob.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}		
}

void testExecutingShrubbery()
{
	try
	{
		ShrubberyCreationForm shrubbery("Home");
		Bureaucrat nico("Nico", 140);
		Bureaucrat rob("Rob", 137);

		nico.signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		rob.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}		
}

void testExecutingRobotomy()
{
	try
	{
		RobotomyRequestForm robotomy("Bender");
		Bureaucrat boss("Boss", 1);

		boss.signForm(robotomy);
		boss.executeForm(robotomy);
		std::cout << std::endl;
		boss.executeForm(robotomy);
		std::cout << std::endl;
		boss.executeForm(robotomy);
		std::cout << std::endl;
		boss.executeForm(robotomy);
		std::cout << std::endl;
		boss.executeForm(robotomy);
		std::cout << std::endl;
		boss.executeForm(robotomy);
		std::cout << std::endl;
		boss.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void testExecutingPardon()
{
	try
	{
		PresidentialPardonForm pardon("Jack");
		Bureaucrat boss("Boss", 1);

		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void testCreatingInvalidForm()
{
	try
	{
		Intern intern;
		AForm *form = intern.makeForm("InvalidForm", "Target");
		if (form)
			delete form; // Clean up if the form was created
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void testIntern()
{
	Intern intern;
    AForm *shrubbery = nullptr;
    AForm *robotomy = nullptr;
    AForm *pardon = nullptr;
    AForm *invalid = nullptr;

    try
    {
        shrubbery = intern.makeForm("shrubbery creation", "Home");
        robotomy = intern.makeForm("robotomy request", "Bender");
        pardon = intern.makeForm("presidential pardon", "Jack");
        invalid = intern.makeForm("invalid form", "Target");

        std::cout << *shrubbery << std::endl;
        std::cout << *robotomy << std::endl;
        std::cout << *pardon << std::endl;
        std::cout << *invalid << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete invalid;
}
