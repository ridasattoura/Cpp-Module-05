#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        explicit PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &target);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &target);
        virtual ~PresidentialPardonForm();
    
    private:
        virtual void executeAction() const;

};

#endif