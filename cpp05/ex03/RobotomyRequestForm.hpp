#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        explicit RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &target);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &target);
        virtual ~RobotomyRequestForm();
    
    private:
        virtual void executeAction() const;

};

#endif