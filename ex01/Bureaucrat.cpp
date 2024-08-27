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
    try
    {
        _Grade--;
        if (_Grade < 1)
        {
            throw Bureaucrat::GradeTooHighException();
            return;
        }
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
        _Grade++;
        if (_Grade > 150)
        {
            throw Bureaucrat::GradeTooLowException();
            return ;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name)
{
    try
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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(Form &F)
{
    try
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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
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