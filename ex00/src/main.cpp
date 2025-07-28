#include "../inc/Bureaucrat.hpp"
#include "../inc/tests.hpp"
#include <iostream>

int main()
{
	testGradeOutOfRange();
	std::cout << "------------------------" << std::endl;
	testIncrementDecrement();
	std::cout << "------------------------" << std::endl;
	testIncrementOutOfRange();
	std::cout << "------------------------" << std::endl;
	testDecrementOutOfRange();
	std::cout << "------------------------" << std::endl;
	testCopyConstructor();
	std::cout << "------------------------" << std::endl;
	std::cout << "All tests completed." << std::endl;
	return 0;	
}