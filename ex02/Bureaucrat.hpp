/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:55:08 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 04:09:42 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
    // Exceptions pour gérer les grades hors limites
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw(); // throw() est nécessaire pour la conformité à C++98
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw(); // throw() est nécessaire pour la conformité à C++98
    };
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    // Getters
    const std::string& getName() const;
    int getGrade() const;
    // Méthodes pour ajuster le grade
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form) const;
    void executeForm(AForm const & form) const;

private:
    const std::string name;
    int grade;
     // Vérifie si le grade est valide
    void checkGrade(int grade);
};
// Surcharge de l'opérateur << pour afficher le Bureaucrat
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
