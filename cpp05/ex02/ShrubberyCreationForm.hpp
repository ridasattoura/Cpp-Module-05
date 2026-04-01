#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        explicit ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &target);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &target);
        virtual ~ShrubberyCreationForm();
    
    private:
        virtual void executeAction() const;

};

#endif