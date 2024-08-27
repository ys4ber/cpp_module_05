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
    _Grade--;
    if (_Grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

void Bureaucrat::Decrement()
{
    _Grade++;
    if (_Grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
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

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _Name(other._Name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    _Grade = other._Grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Bureaucrat assignation operator called" << std::endl;
    _Grade = other._Grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW";
}