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
    try
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

            file << "                     - - -"
                << "-        -  -     --    -"
                << "                -                 -         -  -"
                << "                                -"
                << "                               -                --"
                << "               -          -            -              -"
                << "               -            '-,        -               -"
                << "               -              'b      *"
                << "                -              '$    #-                --"
                << "               -    -           $:   #:               -"
                << "             --      -  --      *#  @):        -   - -"
                << "                          -     :@,@):   ,-**:'   -"
                << "              -      -,         :@@*: --**'      -   -"
                << "                       '#o-    -:(@'-@*\"'  -"
                << "               -  -       'bq,--:,@@*'   ,*      -  -"
                << "                          ,p$q8,:@)'  -p*'      -"
                << "                   -     '  - '@@Pp@@*'    -  -"
                << "                    -  - --    Y7'.'     -  -"
                << "                              :@):."
                << "                             .:@:'."
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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}