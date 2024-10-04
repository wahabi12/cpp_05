/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 04:37:31 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 04:37:49 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructeur par défaut
Intern::Intern() {}

// Constructeur par copie
Intern::Intern(const Intern& other) {
    *this = other;
}

// Opérateur d'affectation
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

// Destructeur
Intern::~Intern() {}

// Méthode pour créer un ShrubberyCreationForm
AForm* Intern::makeShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

// Méthode pour créer un RobotomyRequestForm
AForm* Intern::makeRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

// Méthode pour créer un PresidentialPardonForm
AForm* Intern::makePresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

// Méthode makeForm pour créer un formulaire selon le nom
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    // Tableau des noms de formulaires et des fonctions associées
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formMakers[3])(const std::string& target) const = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
    };

    // Boucle pour rechercher le bon formulaire
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formMakers[i])(target);
        }
    }

    // Si le formulaire n'est pas trouvé, affiche un message d'erreur
    std::cerr << "Error: Form '" << formName << "' does not exist." << std::endl;
    return nullptr;
}
