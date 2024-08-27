#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
    int a = 4;
    int b = 0;

    try
    {
        int c = a / b;
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}