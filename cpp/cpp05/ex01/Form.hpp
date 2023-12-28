/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:08:29 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/28 16:43:22 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool sign;
        const int gradeSign;
        const int gradeExecute;
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw(){return "Grade too Low";};    
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw(){return "Grade too High";};    
        };
        Form();
        Form(std::string name, int gradesign, int gradeexecute);
        ~Form();
        Form(const Form &from);
        const Form &operator=(const Form &form);
        std::string getName() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        bool getSign() const;
        void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif