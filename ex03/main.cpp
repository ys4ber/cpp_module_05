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

        std::cout << "\n----- Testing Intern form creation -----\n" << std::endl;
        Intern intern;
        AForm* Form1 = NULL;
        AForm* Form2 = NULL;
        AForm* Form3 = NULL;
        AForm* Form4 = NULL;

        try {
            Form1 = intern.makeForm("Shrubbery Creation", "garden");
            if (Form1)
            {
                john.signForm(*Form1);
                john.executeForm(*Form1);
            }
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            Form2 = intern.makeForm("Robotomy Request", "robot");
            if (Form2)
            {
                alice.signForm(*Form2);
                john.executeForm(*Form2);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        try
        {
            Form3 = intern.makeForm("Presidential Pardon", "target");
            if (Form3)
            {
                john.signForm(*Form3);
                john.executeForm(*Form3);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        try
        {
            std::cout << "----- Testing unknown form -----" << std::endl;
            Form4 = intern.makeForm("unknown form", "test");
            if (Form4)
            {
                john.signForm(*Form4);
                john.executeForm(*Form4);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        delete Form1;
        delete Form2;
        delete Form3;
        delete Form4;

    return 0;
}
