#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	const std::string filename = getTarget() + "_shrubbery";
	std::ofstream out(filename.c_str());
	if (!out)
		return;

	out << "       _-_-  _/\\__/\\__\n";
	out << "    _-_-__  /\\\\\\\\\\\\\n";
	out << " _-_-__-_- /\\\\\\\\\\\\\\\\\n";
	out << "   _-_-__  \\\\\
";
	out << "     _-_-   \\\\n";
	out << "      ||     ||\n";
	out << "      ||     ||\n";
}