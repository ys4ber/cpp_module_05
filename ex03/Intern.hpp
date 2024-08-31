#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &other);
        Intern &operator=(Intern const &other);
        ~Intern();
        AForm *makeForm(const std::string &name,const std::string &target);
}; 