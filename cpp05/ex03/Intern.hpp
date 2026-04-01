#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &ohter);
        Intern &operator=(const Intern &ohter);
        ~Intern();

        AForm *makeForm(const std::string &formname, const std::string &target) const;

};

#endif
