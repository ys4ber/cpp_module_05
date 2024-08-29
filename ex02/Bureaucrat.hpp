#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string _Name;
        int _Grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();
        
        void setName(std::string name);
        const std::string getName() const;
        void setGrade(int grade);
        int getGrade() const;

        void Decrement();
        void Increment();

        void signForm(AForm &F);
        void executeForm(AForm const & form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
