#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "Creating Bureaucrats:\n";
    Bureaucrat john("John", 2);
    Bureaucrat jane("Jane", 150);

    std::cout << john << std::endl;
    std::cout << jane << std::endl;

    std::cout << "Creating Forms:" << std::endl;
    Form formA("FormA", 2, 10);
    Form formB("FormB", 150, 150);

    std::cout << formA << std::endl;
    
    std::cout << "=====================\n" << std::endl;
    john.signForm(formA); // success
    std::cout << "\n-----------------------\n"<< std::endl;
    jane.signForm(formB); // success
    std::cout << "\n-----------------------\n" << std::endl;
    jane.signForm(formA); // failed
    std::cout << "\n=====================\n" << std::endl;

    std::cout << "Form status after signing attempts:" << std::endl;
    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

    std::cout << "Testing increment and decrement on Bureaucrat grades:\n";

    john.Increment();
    jane.Decrement();

    std::cout << john << std::endl;
    std::cout << jane << std::endl;

    return 0;
}
