/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:08:26 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/28 16:19:48 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm(): name("yy"),gradeSign(1),gradeExecute(1),sign(false){}

AForm::AForm(std::string name, int gradesign, int gradeexecute):name(name),gradeSign(gradesign),gradeExecute(gradeexecute){this->sign = false;}

AForm::~AForm(){}

AForm::AForm(const AForm &from):name(from.name),gradeSign(from.gradeSign),gradeExecute(from.gradeExecute),sign(from.sign){}

const AForm &AForm::operator=(const AForm &form)
{
    if(this != &form)
        this->sign = form.gradeSign;
    return *this;
}

std::string AForm::getName() const{return this->name;}

int AForm::getGradeSign() const {return this->gradeSign;}

int AForm::getGradeExecute() const{return this->gradeExecute;}

bool AForm::getSign() const{return this->sign;}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(gradeSign < bureaucrat.getGrade())
        throw GradeTooLowException();
    this->sign = true;
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
{
    o<<"mane of form is : "<<form.getName()<<" form is sign : "<<form.getSign() <<"grade required to sign is : "<<form.getGradeSign()<<" grade required to execute : "<<form.getGradeExecute()<<std::endl;
}