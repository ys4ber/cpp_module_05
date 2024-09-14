#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{  
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);
    
    ShrubberyCreationForm shrubbery("Garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");
    
    std::cout << "\n-------- Signing forms with alice --------\n" << std::endl;
    try
    {
        alice.signForm(shrubbery);
        alice.signForm(robotomy);
        alice.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n-------- Executing forms with alice --------\n" << std::endl;
    try
    {
        shrubbery.execute(alice);
        robotomy.execute(alice);
        pardon.execute(alice);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n-------- Executing forms with bob --------\n" << std::endl;
    try
    {
        bob.executeForm(shrubbery);  // Should throw an exception
        bob.executeForm(robotomy);   // Should throw an exception
        bob.executeForm(pardon);     // Should throw an exception
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
