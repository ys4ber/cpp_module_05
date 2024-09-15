#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
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
    if (_Grade <= 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (_Grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _Grade--;   
}

void Bureaucrat::Decrement()
{
    if (_Grade >= 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    if (_Grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    _Grade++;
}

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _Grade = grade;
}

void Bureaucrat::signForm(Form &F)
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
    return "Grade is too HIGH 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW 1";
}