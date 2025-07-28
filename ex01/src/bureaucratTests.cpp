#include "../inc/tests.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

void testGradeOutOfRange()
{
	std::cout << "Testing Bureaucrat grade out of range exceptions:" << std::endl;
	try
	{
		Bureaucrat john("John", 75);
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bob("Bob", 0);
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat alice("Alice", 151);
		std::cout << alice << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testIncrementDecrement()
{
	std::cout << "Testing Bureaucrat increment and decrement:" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 50);
		std::cout << charlie << std::endl;
		charlie.incrementGrade();
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testIncrementOutOfRange()
{
	std::cout << "Testing Bureaucrat increment out of range:" << std::endl;
	try
	{
		Bureaucrat dave("Dave", 1);
		std::cout << dave << std::endl;
		std::cout << "Attempting to increment " << dave.getName() << "'s grade:" << std::endl;
		dave.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testDecrementOutOfRange()
{
	std::cout << "Testing Bureaucrat decrement out of range:" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 150);
		std::cout << eve << std::endl;
		std::cout << "Attempting to decrement " << eve.getName() << "'s grade:" << std::endl;
		eve.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testCopyConstructor()
{
	std::cout << "Testing Bureaucrat copy constructor:" << std::endl;
	try
	{
		Bureaucrat frank("Frank", 100);
		std::cout << frank << std::endl;
		Bureaucrat frankCopy(frank);
		std::cout << "Copied Bureaucrat: " << frankCopy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

