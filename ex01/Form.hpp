#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        const std::string _Name;
        bool _Signed;
        const int Grade_sign;
        const int Grade_exec;
    public:
        Form(std::string name, int gs, int ge);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();
        std::string getName() const;
        bool getSigned() const;
        int getGrade_sign() const;
        int getGrade_exec() const;

        void beSigned(Bureaucrat &B); 

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

std::ostream &operator<<(std::ostream &out , Form const &Form);