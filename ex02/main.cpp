#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

        Bureaucrat alice("Alice", 1);  // High-ranking bureaucrat
        Bureaucrat bob("Bob", 150);    // Low-ranking bureaucrat
        
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
    return 0;
}
