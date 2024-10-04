/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 04:37:21 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 04:42:39 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"  // Inclusion de AForm pour les formulaires
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Méthode makeForm qui crée un formulaire
    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    AForm* makeShrubberyCreationForm(const std::string& target) const;
    AForm* makeRobotomyRequestForm(const std::string& target) const;
    AForm* makePresidentialPardonForm(const std::string& target) const;
};

#endif
