#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > 0 && bureaucrat.getGrade() < 151)
    {
        out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
        return out;
    }
    out << "Bureaucrat is out of range" << std::endl;
    return out;

}

const std::string Bureaucrat::getName() const
{
    return _Name;
}

int Bureaucrat::getGrade() const
{
    return _Grade;
}

void Bureaucrat::Increment()
{
    if (_Grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    _Grade--;
}

void Bureaucrat::Decrement()
{
    if (_Grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _Grade++;
}

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name)
{
    if (grade > 0 && grade < 151)
    {
        _Grade = grade;
    }
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

void Bureaucrat::signForm(AForm &F)
{
    F.beSigned(*this);
    if (F.getSigned() == true)
    {
        std::cout << getName() << " signed " << F.getName() << std::endl;
    }
    else if (F.getSigned() == false)
    {
        std::cout << getName() << " couldn't sign " << F.getName() << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (form.getSigned() == true && _Grade <= form.getGrade_exec())
    {
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    else if (form.getSigned() == false && _Grade <= form.getGrade_exec())
    {
        std::cout << getName() << " couldn't execute " << form.getName() << " because :";
        throw Bureaucrat::FormNotSigned();
    }
    else
    {
        std::cout << getName() << " couldn't execute " << form.getName() << " because :";
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _Name(other._Name)
{
    _Grade = other._Grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    _Grade = other._Grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW";
}

const char *Bureaucrat::FormNotSigned::what() const throw()
{
    return "Form is not signed";
}