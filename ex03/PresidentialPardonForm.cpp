#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("President", 25 , 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == true && executor.getGrade() <= getGrade_exec())
    {
        std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
    }
    else if (getSigned() == false && executor.getGrade() <= getGrade_exec())
    {
        std::cout << getName() << " is not signed yet" << std::endl;
    }
    else
    {
        throw GradeTooLowException();
    }
}