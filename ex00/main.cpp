#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
    int a = 23;
    try
    {
        if(a < 5)
            std::cout << "a is less than 5\n";
        else
        {
            throw("helloo sdfsf sdfsf sfsdf");
            std::cout << "heeeeeeeeeeere" << std::endl;
        }
        std::cout << "heere afrer try" << std::endl;   
    }
    catch(const char *b)
    {
       std::cout << "Caught an exception -- value is: " << a << std::endl;
    }
}