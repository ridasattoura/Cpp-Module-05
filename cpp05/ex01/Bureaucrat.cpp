#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::checkGrade(int grade)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat():_name("Default"), _grade(150)
{}
Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) ,_grade(grade) 
{
    Bureaucrat::checkGrade(_grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name) ,_grade(other._grade) 
{
    Bureaucrat::checkGrade(_grade);
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    if( this != &other)
    {
        _grade = other._grade;
        Bureaucrat::checkGrade(_grade);
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade()const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    Bureaucrat::checkGrade(_grade - 1);
    _grade -=1;
}
void Bureaucrat::decrementGrade()
{
    Bureaucrat::checkGrade(_grade + 1);
    _grade +=1;
}

void Bureaucrat::signForm(Form &Form) const
{
    try
    {
        Form.beSigned(*this);
        std::cout << getName() << " signed " << Form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << getName() << " couldn’t sign " << Form.getName() << " because " << e.what() << "." << std::endl;
    }
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low";
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high";
}
std::ostream &operator<<(std::ostream &os,const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}