#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form someForm("beautiful form", 130, 30);
		Bureaucrat someDude("Dave", 131);

		someDude.signForm(someForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}