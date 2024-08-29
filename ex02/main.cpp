#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{

    std::cout << "this is test for ShrubberyCreationForm: \n" << std::endl; 

    ShrubberyCreationForm form("home");
    Bureaucrat alice("Alice", 1);
    form.beSigned(alice);    
    Bureaucrat charlie("Charlie", 14);
    form.execute(charlie);
    std::cout << "\n\n------------------------\n" << std::endl;

    return 0;
}
