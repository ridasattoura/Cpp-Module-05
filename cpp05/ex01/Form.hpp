#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        Form();
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        const std::string &getName() const;
        int getGradeToSign() const;
        int getGradeExecute() const;
        bool isSigned() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };

        static void checkGrade(int grade);
};

std::ostream &operator<<(std::ostream &os,const Form &f);

#endif