#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "***Creating Bureaucrats:\n" << std::endl;
        Bureaucrat john("John", 2);
        Bureaucrat jane("Jane", 150);

        std::cout << john << std::endl;
        std::cout << jane << std::endl;

        std::cout << "***Creating Forms:\n" << std::endl;
        Form formA("FormA", 2, 10);
        Form formB("FormB", 155, 150);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        std::cout << "=====================\n" << std::endl;
        john.signForm(formA); // success
        std::cout << "-----------------------"<< std::endl;
        jane.signForm(formB); // success
        std::cout << "-----------------------" << std::endl;
        // jane.signForm(formA); // failed
        // std::cout << "\n=====================\n" << std::endl;

        std::cout << "***Form status after signing attempts:" << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        std::cout << "\n***Testing increment and decrement on Bureaucrat grades:\n\n";

        john.Increment();
        jane.Decrement();

        std::cout << john << std::endl;
        std::cout << jane << std::endl;
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
