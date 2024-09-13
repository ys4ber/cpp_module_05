#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {   
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        // Alice (high-ranking) will sign and execute the forms
        alice.signForm(shrubbery);
        alice.signForm(robotomy);
        alice.signForm(pardon);

        std::cout << "\nExecuting forms with Alice:\n";
        shrubbery.execute(alice);
        robotomy.execute(alice);
        pardon.execute(alice);

        // Try to execute with Alice (success expected)
    
        // // Bob (low-ranking) will try to execute the forms (should throw exception)
        std::cout << "\nExecuting forms with Bob:\n";
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
