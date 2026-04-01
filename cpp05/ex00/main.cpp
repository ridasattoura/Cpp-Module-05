#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "\n== Valid construction + operator<< ==\n";
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n== Invalid construction ==\n";
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n== Increment boundary (1 is highest) ==\n";
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n== Decrement boundary (150 is lowest) ==\n";
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n== Increment/decrement normal ==\n";
	try
	{
		Bureaucrat b("Bob", 3);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}