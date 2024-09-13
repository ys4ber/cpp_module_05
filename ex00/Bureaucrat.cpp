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
    try
    {
        if (_Grade <= 1)
        {
            throw Bureaucrat::GradeTooHighException();
        }
        if (_Grade > 150)
        {
            throw Bureaucrat::GradeTooHighException();
        }
        _Grade--;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

void Bureaucrat::Decrement()
{
    try
    {
        if (_Grade >= 150)
        {
            throw Bureaucrat::GradeTooLowException();
        }
        if (_Grade < 1)
        {
            throw Bureaucrat::GradeTooLowException();
        }
       _Grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    try
    {
        _Grade = grade;
        if (grade < 1)
        {
            throw Bureaucrat::GradeTooHighException();
        }
        if (grade > 150)
        {
            throw Bureaucrat::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
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