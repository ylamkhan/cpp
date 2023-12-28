/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:08:26 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/28 16:41:43 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(): name("yy"),gradeSign(1),gradeExecute(1),sign(false){}

Form::Form(std::string name, int gradesign, int gradeexecute):name(name),gradeSign(gradesign),gradeExecute(gradeexecute){this->sign = false;}

Form::~Form(){}

Form::Form(const Form &from):name(from.name),gradeSign(from.gradeSign),gradeExecute(from.gradeExecute),sign(from.sign){}

const Form &Form::operator=(const Form &form)
{
    if(this != &form)
        this->sign = form.gradeSign;
    return *this;
}

std::string Form::getName() const{return this->name;}

int Form::getGradeSign() const {return this->gradeSign;}

int Form::getGradeExecute() const{return this->gradeExecute;}

bool Form::getSign() const{return this->sign;}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(gradeSign < bureaucrat.getGrade())
        throw GradeTooLowException();
    else
        this->sign = true;
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
    o<<"mane of form is : "<<form.getName()<<" form is sign : "<<form.getSign() <<"grade required to sign is : "<<form.getGradeSign()<<" grade required to execute : "<<form.getGradeExecute()<<std::endl;
}