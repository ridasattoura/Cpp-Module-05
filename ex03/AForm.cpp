#include "AForm.hpp"

#include "Bureaucrat.hpp"

void AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150), _target("default")
{
}

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	AForm::validateGrade(_gradeToSign);
	AForm::validateGrade(_gradeToExecute);
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target)
{
	AForm::validateGrade(_gradeToSign);
	AForm::validateGrade(_gradeToExecute);
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		// _name/_target/_gradeToSign/_gradeToExecute are const; only signed state can be assigned.
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return _name;
}

const std::string &AForm::getTarget() const
{
	return _target;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm " << f.getName() << ", target: " << f.getTarget() << ", signed: " << (f.isSigned() ? "true" : "false")
	   << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute() << ".";
	return os;
}
