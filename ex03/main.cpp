#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main() 
{

        Bureaucrat bob("Bob", 1);       // Highest grade
        Bureaucrat alice("Alice", 50);  // Mid-grade
        Bureaucrat john("John", 150);   // Lowest grade

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("criminal");

        try
        {
            std::cout << "----- Testing signing -----" << std::endl;
            bob.signForm(shrubbery);
            alice.signForm(robotomy);
            john.signForm(pardon);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try {
            std::cout << "----- Testing execution -----" << std::endl;
            bob.executeForm(shrubbery); // Bob can execute since he signed it
            bob.executeForm(robotomy);  // Bob executes robotomy (random success)
            john.executeForm(pardon);    // Bob executes the presidential pardon
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "----- Testing Intern form creation -----" << std::endl;
        Intern intern;
        AForm* newForm;

        try {        
            newForm = intern.makeForm("Shrubbery Creation", "garden");
            if (newForm)
            {
                john.signForm(*newForm);
                john.executeForm(*newForm);
                delete newForm;
            }
        }
        catch (std::exception &e)
        {
            delete newForm;
            std::cerr << e.what() << std::endl;
        }

        try
        {
            newForm = intern.makeForm("Robotomy Request", "robot");
            if (newForm)
            {
                alice.signForm(*newForm);
                john.executeForm(*newForm);
                delete newForm;
            }
        }
        catch(const std::exception& e)
        {
            delete newForm;
            std::cerr << e.what() << '\n';
        }
        
        try
        {
            newForm = intern.makeForm("Presidential Prdon", "target");
            if (newForm)
            {
                john.signForm(*newForm);
                john.executeForm(*newForm);
                delete newForm;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        try {
            std::cout << "----- Testing unknown form -----" << std::endl;
            newForm = intern.makeForm("unknown form", "test");
            delete newForm;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    return 0;
}
