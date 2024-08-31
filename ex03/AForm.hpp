#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
        const std::string _Name;
        bool _Signed;
        const int Grade_sign;
        const int Grade_exec;
    public:
        AForm(std::string name, int gs, int ge);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        virtual ~AForm();
        std::string getName() const;
        bool getSigned() const;
        int getGrade_sign() const;
        int getGrade_exec() const;
;
        void beSigned(Bureaucrat &B);

        virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream &operator<<(std::ostream &out , AForm const &Form);