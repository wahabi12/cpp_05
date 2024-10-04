/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:52:58 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 03:57:09 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::srand(std::time(nullptr));  // Initialisation du générateur de nombres aléatoires
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);  // Vérification avant exécution
    std::cout << "* Drilling noises *" << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy failed." << std::endl;
    }
}
