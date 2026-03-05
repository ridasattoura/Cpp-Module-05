#include "Form.hpp"

#include "Bureaucrat.hpp"

void Form::validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	Form::validateGrade(_gradeToSign);
	Form::validateGrade(_gradeToExecute);
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	Form::validateGrade(_gradeToSign);
	Form::validateGrade(_gradeToExecute);
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// _name/_gradeToSign/_gradeToExecute are const; only signed state can be assigned.
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName() << ", signed: " << (f.isSigned() ? "true" : "false")
	   << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute() << ".";
	return os;
}
