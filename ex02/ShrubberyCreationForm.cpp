#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrub", 145, 137)
{
    this->target = target;   
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == true && executor.getGrade() <= getGrade_exec())
    {
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
        std::string str = target + "_shrubbery";
        std::ofstream file(str.c_str());
        if (!file.is_open())
        {
            std::cerr << "cannot create file" << std::endl;
            return;
        }

        file << "                     - - -\n"
            << "-        -  -     --    -\n"
            << "                -                 -         -  -\n"
            << "                                -\n"
            << "                               -                --\n"
            << "               -          -            -              -\n"
            << "               -            '-,        -               -\n"
            << "               -              'b      *\n"
            << "                -              '$    #-                --\n"
            << "               -    -           $:   #:               -\n"
            << "             --      -  --      *#  @):        -   - -\n"
            << "                          -     :@,@):   ,-**:'   -\n"
            << "              -      -,         :@@*: --**'      -   -\n"
            << "                       '#o-    -:(@'-@*\"'  -\n"
            << "               -  -       'bq,--:,@@*'   ,*      -  -\n"
            << "                          ,p$q8,:@)'  -p*'      -\n"
            << "                   -     '  - '@@Pp@@*'    -  -\n"
            << "                    -  - --    Y7'.'     -  -\n"
            << "                              :@):.\n"
            << "                             .:@:'.\n"
            << "                           .::(@:.      يعقوب قمر الدين دبيازة";
        file.close();
    }
    else if (getSigned() == false )
    {
        std::cout << "The form " << this->getName() << " not signed yet" << std::endl;
    }
    else
    {
        std::cout << executor.getName() << " cannot execute " << this->getName() << " because ";
        throw GradeTooLowException(); 
    }
}