#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", 75, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    target = other.target;
    return *this;
} 

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    srand(time(NULL));
    if (getSigned() == true && executor.getGrade() <= getGrade_exec())
    {
        std::cout << getName() << "Makes some drilling noises" << std::endl;
        if (rand() % 2 == 0)
        {
            std::cout << target << " has been robotomized successfully" << std::endl;
        }
        else
        {
            std::cout << target << " has failed to be robotomized" << std::endl;
        }
    }
    else
    {
        throw Bureaucrat::GradeTooLowException();
    }
}