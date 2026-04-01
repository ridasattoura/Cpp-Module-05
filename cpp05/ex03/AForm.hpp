#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
        const std::string _target;


    public:
        AForm();
        AForm(const std::string name, const std::string &target, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();

        const std::string &getName() const;
        const std::string &getTarget() const;
        int getGradeToSign() const;
        int getGradeExecute() const;
        bool isSigned() const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeNotSignedException : public std::exception
        {
            virtual const char *what() const throw();
        };

        static void checkGrade(int grade);
        virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os,const AForm &f);

#endif