#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>


int main()
{
	std::cout << "== Unsigned execute should fail ==" << std::endl;
	{
		Bureaucrat exec("Exec", 1);
		RobotomyRequestForm f("Marvin");
		exec.executeForm(f);
	}

	std::cout << "== Sign but execute with too-low grade should fail ==" << std::endl;
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat lowExec("LowExec", 150);
		PresidentialPardonForm f("Ford");

		signer.signForm(f);
		lowExec.executeForm(f);
	}

	std::cout << "== Shrubbery creation success (creates file) ==" << std::endl;
	{
		Bureaucrat b("Gardener", 1);
		ShrubberyCreationForm f("home");
		b.signForm(f);
		b.executeForm(f);
		std::cout << "Check for file: home_shrubbery" << std::endl;
	}

	std::cout << "== Robotomy: 50% success ==" << std::endl;
	{
		Bureaucrat b("Rob", 1);
		RobotomyRequestForm f("Bender");
		b.signForm(f);
		for (int i = 0; i < 4; ++i)
			b.executeForm(f);
	}

	std::cout << "== Presidential pardon success ==" << std::endl;
	{
		Bureaucrat b("Prez", 1);
		PresidentialPardonForm f("Arthur");
		b.signForm(f);
		b.executeForm(f);
	}

	return 0;
}