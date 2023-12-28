#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default"),grade(15){}

Bureaucrat::Bureaucrat(std::string name , int grade) : name(name)
{
    if(grade  < 0 || grade > 150)
    {
        if(grade < 0)
            throw GradeTooHighException();
        else
            throw GradeTooLowException();
    }
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): name(bureaucrat.name),grade(bureaucrat.grade){}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if(this != &bureaucrat)
        grade = bureaucrat.grade;
    return(*this);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    if(this->grade - 1 < MAX_GRADE)
        throw GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade > MIN_GRADE)
        throw GradeTooLowException();
    else
        this->grade++;
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"destructor Bureaucrat called"<<std::endl;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat)
{
    o<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade() <<" .";
    return(o);
}

