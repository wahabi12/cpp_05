/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:51:50 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 03:56:49 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);  // Vérification avant exécution
    std::ofstream outfile(target + "_shrubbery");
    if (outfile) {
        outfile << "ASCII Trees" << std::endl;
        outfile.close();
    } else {
        std::cerr << "Error creating file." << std::endl;
    }
}
