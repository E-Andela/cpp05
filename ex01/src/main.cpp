#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form someForm("beautiful form", 130, 30);
		Bureaucrat someDude("Dave", 129);

		std::cout << someForm << std::endl;
		someDude.signForm(someForm);
		std::cout << someForm << std::endl;
		someForm.beSigned(someDude);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}