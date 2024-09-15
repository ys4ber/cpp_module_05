#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "***Creating Bureaucrats:\n" << std::endl;

    try
    {
        Bureaucrat john("John", 1);
        Bureaucrat jane("Jane", 15);

        std::cout << john << std::endl;
        std::cout << jane << std::endl;

        std::cout << "***Creating Forms:\n" << std::endl;

        Form formA;
        Form formB;

        try
        {
            formA = Form("FormA", 1, 1);
            formB = Form("FormB", 150, 150);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << "=====================\n" << std::endl;
        try
        {
            john.signForm(formA); // success
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "-----------------------"<< std::endl;

        try
        {
            jane.signForm(formB); // success
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "-----------------------" << std::endl;
        std::cout << "***Form status after signing attempts:" << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << "\n***Testing increment and decrement on Bureaucrat grades:\n\n";
        try
        {
            john.Increment();    
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << "------- testing decrement -------" << std::endl;
        try
        {
            jane.Decrement();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << john << std::endl;
        std::cout << jane << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
