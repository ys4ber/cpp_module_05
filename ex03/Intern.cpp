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

int _Check_Valid_Name(const std::string &name)
{
    std::string names[3] = {"Robotomy Request", "Presidential Pardon", "Shrubbery Creation"};
    if (name != names[0] && name != names[1] && name != names[2])
    {
        return -1;
    }
    return 0;
}

const char *Intern::InvalidFormException::what() const throw()
{
    return "FORM DOESN'T EXIST!!!!!!!!!!!!";
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    if (_Check_Valid_Name(name) == -1)
    {
        throw Intern::InvalidFormException();
    }
    switch (name[0])
    {
        case 'R':
            return new RobotomyRequestForm(target);
            break;
        case 'P':
            return new PresidentialPardonForm(target);
            break;
        case 'S':
            return new ShrubberyCreationForm(target);
            break;
        default:
            throw Intern::InvalidFormException();
            break;
    }
    std::cerr << "this form doesn't exist" << std::endl;
    return NULL;
}