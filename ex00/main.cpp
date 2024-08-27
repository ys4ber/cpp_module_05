#include "Bureaucrat.hpp"

// class Bureaucrat {
//     int grade;
// public:
//     Bureaucrat(int g) : grade(g) {
//         if (g < 1)
//             throw std::out_of_range("Grade must be between 1 and 150");
//         if (g > 150)
//             throw std::out_of_range("sfhkjjjjjhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");
//     }
// };

// int main() {
//     try {
//         Bureaucrat b1(100);  // This is fine
//         Bureaucrat b2(200);  // This will throw an exception
//     }
//     catch (const std::exception& e) {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//     }
//     return 0;
// }

int main()
{
    Bureaucrat B1("B1", 25);
    std::cout << B1.getName() << std::endl;
    std::cout << B1.getGrade() << std::endl;

    
}