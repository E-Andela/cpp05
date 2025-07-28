#include "../inc/tests.hpp"
#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

void testFormConstructor() {
	try {
		Form form("Form", 50, 100);
		std::cout << form << std::endl;
		std::cout << "Form constructor test passed." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Form constructor test failed: " << e.what() << std::endl;
	}
	// Test with invalid sign grade; too high
	try {
		Form form("Form", 0, 100);
	} catch (const std::exception &e) {
		std::cout << "Form constructor test failed: " << e.what() << std::endl;
	}
	// Test with invalid exec grade; too high
	try {
		Form form("Form", 50, 0);
	} catch (const std::exception &e) {
		std::cout << "Form constructor test failed: " << e.what() << std::endl;
	}
	// Test with invalid sign grade; too low
	try {
		Form form("Form", 151, 100);
	} catch (const std::exception &e) {
		std::cout << "Form constructor test failed: " << e.what() << std::endl;
	}
	// Test with invalid exec grade; too low
	try {
		Form form("Form", 50, 151);
	} catch (const std::exception &e) {
		std::cout << "Form constructor test failed: " << e.what() << std::endl;
	}
}

void testFormBeSigned() {
	try {
		Form form("Form", 50, 100);
		Bureaucrat bureaucrat("Bureaucrat", 50);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		form.beSigned(bureaucrat);
		std::cout << "Form beSigned test passed." << std::endl;
		std::cout << form << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Form beSigned test failed: " << e.what() << std::endl;
	}

	try {
		Form form("Form", 50, 100);
		Bureaucrat bureaucrat("Bureaucrat", 51);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		// This should throw an exception since the bureaucrat's grade is too low
		form.beSigned(bureaucrat);
	} catch (const std::exception &e) {
		std::cout << "Form beSigned test failed: " << e.what() << std::endl;
	}
}