#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main()
{
    Bureaucrat alice("Alice", 150);
    Intern someRandomIntern;
    AForm* form ;
    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    alice.signForm(*form);
    alice.executeForm(*form);
    delete form;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    alice.signForm(*form);
    alice.executeForm(*form);
    delete form;
    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    alice.signForm(*form);
    alice.executeForm(*form);
    delete form;
    form = someRandomIntern.makeForm("invalid form", "Target");
    if (form)
    {
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
    }
}

