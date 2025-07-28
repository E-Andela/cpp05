#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target {"default"}
{
	#ifdef DEBUG
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other)
	, _target {other._target}
{
	#ifdef DEBUG
	std::cout << "ShrubberyCreationForm copy constructor called for form with target " << other._target << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target {target}
{
	#ifdef DEBUG
	std::cout << "ShrubberyCreationForm constructor called with target " << target << std::endl;
	#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	#endif
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::executeAction(const Bureaucrat &executor) const
{
	std::string filename {_target + "_shrubbery"};
	int tree_height {8};
	int tree_width {tree_height * 2 - 1};

	std::ofstream file(filename);

	// tree canopy
	for (int i = 0; i < tree_height; ++i)
	{
		for (int j = 0; j < tree_width; ++j)
		{
			if (j >= tree_width / 2 - i && j <= tree_width / 2 + i)
				file << '*';
			else
				file << ' ';
		}
		file << std::endl;
	}

	// tree trunk
	for (int i = 0; i < tree_height / 2; ++i)
	{
		for (int j = 0; j < tree_width; ++j)
		{
			if (j == tree_width / 2)
				file << 'H';
			else
				file << ' ';
		}
		file << std::endl;
	}

	file << std::endl << "created by: " << executor.getName() << std::endl;
}