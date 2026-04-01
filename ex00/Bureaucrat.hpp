#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
public:
	/** Default-constructs a Bureaucrat (implementation-defined initial grade). */
	Bureaucrat();

	/**
	 * Constructs a Bureaucrat with a constant name and an initial grade.
	 * @throws GradeTooHighException if grade is above the allowed range.
	 * @throws GradeTooLowException if grade is below the allowed range.
	 */
	Bureaucrat(const std::string &name, int grade);

	/** Copy-constructs from another Bureaucrat. */
	Bureaucrat(const Bureaucrat &other);

	/** Copy-assigns from another Bureaucrat. */
	Bureaucrat &operator=(const Bureaucrat &other);

	/** Destructor. */
	~Bureaucrat();

	/** Returns the Bureaucrat's name. */
	const std::string &getName() const;

	/** Returns the Bureaucrat's current grade. */
	int getGrade() const;

	/**
	 * Promotes the Bureaucrat (decreases the numeric grade).
	 * @throws GradeTooHighException if promotion would exceed the upper bound.
	 */
	void incrementGrade();

	/**
	 * Demotes the Bureaucrat (increases the numeric grade).
	 * @throws GradeTooLowException if demotion would exceed the lower bound.
	 */
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		/** Returns a human-readable description of the error. */
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		/** Returns a human-readable description of the error. */
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	int _grade;

	/** Validates a grade value against the allowed bounds. */
	static void validateGrade(int grade);
};

/** Stream insertion operator for printing a Bureaucrat (format defined in .cpp). */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
