#include "Form.hpp"

Form::Form() : name("Default Form"), sign(false), gradeSign(1), gradeExecute(1) {}

Form::Form(std::string name, unsigned int sign, int gradeSign, int gradeExecute)
    : name(name), sign(sign), gradeSign(gradeSign), gradeExecute(gradeExecute) {}

Form::~Form() {}

Form::Form(const Form &from) : name(from.name), sign(from.sign), gradeSign(from.gradeSign), gradeExecute(from.gradeExecute) {}

const Form &Form::operator=(const Form &form)
{
    if (this != &form)
    {
        // Perform the assignment
        const_cast<std::string &>(name) = form.name; // const_cast is used to modify the const member
        sign = form.sign;
    }
    return *this;
}

const std::string &Form::getName() const
{
    return name;
}

bool Form::getSign() const
{
    return sign;
}

int Form::getGradeSign() const
{
    return gradeSign;
}

int Form::getGradeExecute() const
{
    return gradeExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeSign)
    {
        sign = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

void Form::signForm(Bureaucrat &bureaucrat)
{
    try
    {
        beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signed " << name << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << name << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
    o << "Form: " << form.getName() << ", Sign status: " << (form.getSign() ? "Signed" : "Not signed")
      << ", Grade required to sign: " << form.getGradeSign() << ", Grade required to execute: " << form.getGradeExecute();
    return o;
}
