#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{

}

static AForm *makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    typedef AForm *(*FactoryFn)(const std::string &);
    
    struct Entry
    {
        const char *name;
        FactoryFn fn;
    };

    static const Entry table[] ={
        {"shrubbery creation", &makeShrubbery},
        {"robotomy request", &makeRobotomy},
        {"presidential request", &makePresidential},
    };

    for(size_t i = 0; i < (sizeof(table) / sizeof(table[0])); ++i)
    {
        if(formName == table[i].name)
        {
            AForm *created = table[i].fn(target);
            std::cout << "Intern creates " << created->getName() << std::endl;
            return created;
        }
    }

    std::cout << "Intern couldn't create '" << formName << "' because it doesn't exist." << std::endl;
    return NULL;
}