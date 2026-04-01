#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

static void seedOnce()
{
    static bool seeded = false;
    if(!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }
}

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", "default", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    :AForm("RobotomyRequestForm", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{

}
void RobotomyRequestForm::executeAction() const
{
   seedOnce();
	std::cout << "Bzzzzzz... drrrrrr... *drilling noises*" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << getTarget() << "." << std::endl;
}