/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:24:00 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 03:40:55 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructeur
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    checkGrade(grade);
}
// Destructeur
Bureaucrat::~Bureaucrat() {}
// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}
int Bureaucrat::getGrade() const {
    return grade;
}
// Méthodes pour incrémenter et décrémenter le grade
void Bureaucrat::incrementGrade() {
    checkGrade(grade - 1);
    grade--;
}

void Bureaucrat::decrementGrade() {
    checkGrade(grade + 1);
    grade++;
}

// Vérification du grade
void Bureaucrat::checkGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Implémentation de l'exception GradeTooHighException
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

// Implémentation de l'exception GradeTooLowException
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Surcharge de l'opérateur << pour afficher un Bureaucrat
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);  // Tentative de signer le formulaire
        std::cout << name << " signed " << form.getName() << std::endl;
    } 
    catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
