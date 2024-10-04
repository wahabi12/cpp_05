/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:51:01 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 03:56:13 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade is too high!";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade is too low!";
            }
    };

    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Form is not signed!";
            }
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    virtual ~AForm();

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    // Méthode virtuelle pure
    virtual void execute(Bureaucrat const & executor) const = 0;

protected:
    void checkExecution(Bureaucrat const & executor) const;

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
