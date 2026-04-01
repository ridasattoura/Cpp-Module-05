#include "Bureaucrat.hpp"

#include "Intern.hpp"

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
	header("Intern creates known forms");
	{
		Intern someRandomIntern;
		AForm *s = someRandomIntern.makeForm("shrubbery creation", "home");
		AForm *r = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm *p = someRandomIntern.makeForm("presidential pardon", "Arthur");

		Bureaucrat boss("Boss", 1);
		if (s)
		{
			boss.signForm(*s);
			boss.executeForm(*s);
			std::cout << "Check for file: home_shrubbery" << std::endl;
		}
		if (r)
		{
			boss.signForm(*r);
			boss.executeForm(*r);
		}
		if (p)
		{
			boss.signForm(*p);
			boss.executeForm(*p);
		}

		delete s;
		delete r;
		delete p;
	}

	header("Intern unknown form name");
	{
		Intern intern;
		AForm *unknown = intern.makeForm("form 28B", "target");
		delete unknown;
	}

	header("Execute should fail when unsigned");
	{
		Intern intern;
		Bureaucrat exec("Exec", 1);
		AForm *rrf = intern.makeForm("robotomy request", "Marvin");
		if (rrf)
			exec.executeForm(*rrf);
		delete rrf;
	}

	header("Execute should fail with too-low grade");
	{
		Intern intern;
		Bureaucrat signer("Signer", 1);
		Bureaucrat lowExec("LowExec", 150);
		AForm *ppf = intern.makeForm("presidential pardon", "Ford");
		if (ppf)
		{
			signer.signForm(*ppf);
			lowExec.executeForm(*ppf);
		}
		delete ppf;
	}

	return 0;
}