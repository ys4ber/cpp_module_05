#include "Intern.hpp" 

Intern::Intern()
{
}



Intern::Intern(Intern const &other)
{
    (void)other;
}

Intern& Intern::operator=(Intern const &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    switch (name[0])
    {
    case 's':
        return new ShrubberyCreationForm(target);
    case 'r':
        return new RobotomyRequestForm(target);
    case 'p':
        return new PresidentialPardonForm(target);
    default:
        std::cout << "Invalid form name" << std::endl;
        break;
    }
    return NULL;
}