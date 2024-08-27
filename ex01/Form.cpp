#include "Form.hpp"

std::ostream &operator<<(std::ostream &out , Form const &Form)
{
    out << Form.getName() << "is it signed ? ==" << Form.getSigned() << "==" << std::endl;
    return out;
}

Form::Form(std::string name) : _Name(name) , _Signed(false) , Grade_sign(50), Grade_exec(15)
{
    
}

Form::Form(Form const &other) : Grade_sign(50) , Grade_exec(10)
{
    *this = other;
}

Form &Form::operator=(Form const &other)
{
    _Signed = other._Signed;
    return *this;
}

Form::~Form()
{

}

std::string Form::getName() const
{
    return _Name;
}

bool Form::getSigned() const
{
    return _Signed;
}

int Form::getGrade_sign() const 
{
    return Grade_sign;
}

int Form::getGrade_exec() const
{
    return Grade_exec;
}

void Form::beSigned(Bureaucrat &B)
{
    if (B.getGrade() >= Grade_sign)
    {
        std::cout << "The form has been signed" << std::endl;
        _Signed = true;
    }
}

void Form::signForm(Bureaucrat &B)
{
    if (_Signed == true)
        std::cout << B << " signed " << getName() << std::endl;
    else
        std::cout << B << " couldn't sign " << getName() << " because Grade is too LOW " << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW`";
}
