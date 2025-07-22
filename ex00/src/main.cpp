#include "../inc/Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat b1("Alice", 3);
		Bureaucrat b2("Bob", 150);

		b2 = b1; // Assignment operator
		std::cout << b2 << std::endl;
		b1.incrementGrade();
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		b1.incrementGrade();
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}