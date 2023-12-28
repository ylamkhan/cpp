#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():name("default"),grade(0){}

Bureaucrat::Bureaucrat(std::string name , int grade) :name(name)
{
    if(this->grade - 1 < MAX_GRADE || this->grade > MIN_GRADE)
    {
        if(this->grade - 1 < MAX_GRADE)
            throw GradeToolLowException();
        else
            throw GradeToolHighException();
    }
    else
        this->grade = grade;  
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat):name(bureaucrat.name),grade(bureaucrat.grade){}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if(&bureaucrat != this)
        *this = bureaucrat;
    return(*this);
}

std::string Bureaucrat::getName() const{return (this->name);}

int Bureaucrat::getGrade() const{return (this->grade);}

void Bureaucrat::incrementGrade()
{
    if(this->grade - 1 < MAX_GRADE)
        throw GradeToolLowException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade > MIN_GRADE)
        throw GradeToolHighException();
    else
        this->grade++;
}

Bureaucrat::~Bureaucrat(){}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout<<this->name<<" singed "<<form.getName()<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<this->name<<"couldn't sign" << form.getName()<<"because"<<e.what()<<std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat)
{
    o<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade();
    return(o);
}


