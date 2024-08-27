#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bob("Bob", 540);
    std::cout << bob << std::endl;

    Bureaucrat alice("Alice", 1);
    std::cout << alice << std::endl;


    alice.Increment();
    std::cout << alice << std::endl;


    bob.Decrement();
    std::cout << bob << std::endl;

    Bureaucrat charlie("Charlie", 150);
    std::cout << charlie << std::endl;

    charlie.Decrement();
    std::cout << charlie << std::endl;

    return 0;
}
