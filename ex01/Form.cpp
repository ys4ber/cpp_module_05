#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out , Form const &Form)
{
    out << "\"" <<Form.getName() << "\"  is Signed ? ==> ";
    if (Form.getSigned())
    {
        out << "Yes";
    }
    else
    {
        out << "No";
    }
    return out;
}

Form::Form() : _Name("Default"), _Signed(false), Grade_sign(150), Grade_exec(150)
{

}

Form::Form(std::string name, int gs, int ge) : _Name(name) , _Signed(false) , Grade_sign(gs), Grade_exec(ge)
{

}

Form::Form(Form const &other) : _Name(other._Name), Grade_sign(other.Grade_sign) , Grade_exec(other.Grade_exec)
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
    if (B.getGrade() <= Grade_sign)
    {
        _Signed = true;
    }
    else
    {
        _Signed = false;
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH 2";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW 2";
}
