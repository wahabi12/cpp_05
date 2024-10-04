/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:51:12 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 04:10:14 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructeur
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Destructeur
AForm::~AForm() {}

// Getters
const std::string& AForm::getName() const { return name; }
bool AForm::isSigned() const { return signedStatus; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

// Signature du formulaire
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Vérification de l'exécution
void AForm::checkExecution(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute) {
        throw GradeTooLowException();
    }
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form " << form.getName() << " [Sign: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExecute() << "]";
    return out;
}
