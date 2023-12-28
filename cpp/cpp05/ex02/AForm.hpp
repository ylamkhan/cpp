/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:08:29 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/28 16:45:00 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
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
        AForm();
        AForm(std::string name, int gradesign, int gradeexecute);
        ~AForm();
        AForm(const AForm &from);
        const AForm &operator=(const AForm &AForm);
        std::string getName() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        bool getSign() const;
        void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif