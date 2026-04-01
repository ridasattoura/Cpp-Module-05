#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

static void header(const std::string &title)
{
	std::cout << "\n== " << title << " ==\n";
}

int main()
{
	header("Unsigned execute should fail");
	{
		Bureaucrat exec("Exec", 1);
		RobotomyRequestForm f("Marvin");
		exec.executeForm(f);
	}

	header("Sign but execute with too-low grade should fail");
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat lowExec("LowExec", 150);
		PresidentialPardonForm f("Ford");

		signer.signForm(f);
		lowExec.executeForm(f);
	}

	header("Shrubbery creation success (creates file)");
	{
		Bureaucrat b("Gardener", 1);
		ShrubberyCreationForm f("home");
		b.signForm(f);
		b.executeForm(f);
		std::cout << "Check for file: home_shrubbery" << std::endl;
	}

	header("Robotomy: 50% success");
	{
		Bureaucrat b("Rob", 1);
		RobotomyRequestForm f("Bender");
		b.signForm(f);
		for (int i = 0; i < 4; ++i)
			b.executeForm(f);
	}

	header("Presidential pardon success");
	{
		Bureaucrat b("Prez", 1);
		PresidentialPardonForm f("Arthur");
		b.signForm(f);
		b.executeForm(f);
	}

	return 0;
}