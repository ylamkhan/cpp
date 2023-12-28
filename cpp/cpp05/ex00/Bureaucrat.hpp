/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:39:32 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/28 13:38:21 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150


#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw(){return "Grade too Low";};
                
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw(){return "Grade too High";};
                
        };
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        const Bureaucrat& operator=(const Bureaucrat& bureaucrat);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat);


#endif