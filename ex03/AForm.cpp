#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out , AForm const &Form)
{
    out << Form.getName() << " Form is Signed == " << Form.getSigned() << std::endl;
    return out;
}

AForm::AForm(std::string name, int gs, int ge) : _Name(name) , Grade_sign(gs), Grade_exec(ge)
{
    _Signed = false;
}

AForm::AForm(AForm const &other) : Grade_sign(other.Grade_sign) , Grade_exec(other.Grade_exec) 
{
    _Signed = other._Signed;
    *this = other;
}

AForm &AForm::operator=(AForm const &other)
{
    _Signed = other._Signed;
    return *this;
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
    return _Name;
}

bool AForm::getSigned() const
{
    return _Signed;
}

int AForm::getGrade_sign() const 
{
    return Grade_sign;
}

int AForm::getGrade_exec() const
{
    return Grade_exec;
}

void AForm::beSigned(Bureaucrat &B)
{
    try
    {
        if (B.getGrade() <= Grade_sign)
        {
            _Signed = true;
        }
        else
        {
            _Signed = false;
            throw Bureaucrat::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW`";
}
