/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:25:01 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 03:36:33 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructeur
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form {
public:
    // Exceptions spécifiques à Form
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();  // throw() pour C++98
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();  // throw() pour C++98
    };

    // Constructeur et destructeur
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    ~Form();

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Méthodes
    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;

    void checkGrades() const;  // Vérifier si les grades sont valides
};

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
