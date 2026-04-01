#include "Bureaucrat.hpp"

/** Validates that the provided grade is within [1, 150]. */
void Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/** Default constructor: creates a Bureaucrat named "Default" with the lowest grade. */
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

/** Constructs a Bureaucrat with the given name and grade (validated). */
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	Bureaucrat::validateGrade(_grade);
}

/** Copy constructor: copies name and grade (validated). */
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	Bureaucrat::validateGrade(_grade);
}

/** Copy assignment: assigns grade only (name is const) and validates the result. */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// _name is const, so it cannot be assigned; grade-only assignment is intended.
		_grade = other._grade;
		Bureaucrat::validateGrade(_grade);
	}
	return *this;
}

/** Destructor. */
Bureaucrat::~Bureaucrat()
{
}

/** Returns the Bureaucrat's name. */
const std::string &Bureaucrat::getName() const
{
	return _name;
}

/** Returns the Bureaucrat's current grade. */
int Bureaucrat::getGrade() const
{
	return _grade;
}

/** Promotes the Bureaucrat by decreasing the numeric grade by 1 (validated). */
void Bureaucrat::incrementGrade()
{
	Bureaucrat::validateGrade(_grade - 1);
	_grade -= 1;
}

/** Demotes the Bureaucrat by increasing the numeric grade by 1 (validated). */
void Bureaucrat::decrementGrade()
{
	Bureaucrat::validateGrade(_grade + 1);
	_grade += 1;
}

/** Exception message for attempts to create/promote above the highest allowed grade. */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high";
}

/** Exception message for attempts to create/demote below the lowest allowed grade. */
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low";
}

/** Prints a Bureaucrat as: "<name>, bureaucrat grade <grade>." */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
