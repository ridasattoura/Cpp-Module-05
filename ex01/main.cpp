#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

static void header(const std::string &title)
{
	std::cout << "\n== " << title << " ==\n";
}

int main()
{
	header("Valid Form construction + operator<<");
	try
	{
		Form f("TopSecret", 10, 5);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	header("Invalid Form construction (out of bounds grades)");
	try
	{
		Form tooHigh("TooHigh", 0, 10);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		Form tooLow("TooLow", 10, 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	header("Signing success");
	try
	{
		Bureaucrat alice("Alice", 10);
		Form f("NDA", 10, 50);
		std::cout << alice << std::endl;
		std::cout << f << std::endl;
		alice.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	header("Signing failure (bureaucrat grade too low)");
	try
	{
		Bureaucrat bob("Bob", 100);
		Form f("BudgetApproval", 50, 50);
		std::cout << bob << std::endl;
		std::cout << f << std::endl;
		bob.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
