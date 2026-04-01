#include "Bureaucrat.hpp"

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>


int main()
{
	std::cout << "== Intern creates known forms ==" << std::endl;
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

	std::cout << "== Intern unknown form name ==" << std::endl;
	{
		Intern intern;
		AForm *unknown = intern.makeForm("form 28B", "target");
		delete unknown;
	}

	std::cout << "== Execute should fail when unsigned ==" << std::endl;
	{
		Intern intern;
		Bureaucrat exec("Exec", 1);
		AForm *rrf = intern.makeForm("robotomy request", "Marvin");
		if (rrf)
			exec.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "== Execute should fail with too-low grade ==" << std::endl;
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