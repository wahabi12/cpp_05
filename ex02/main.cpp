/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:50:33 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 04:05:20 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat john("John", 1);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    AForm &form1 = shrub;
    AForm &form2 = robot;
    AForm &form3 = pardon;
    
    try {
        john.signForm(form1);
        john.executeForm(form1);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        john.signForm(form2);
        john.executeForm(form2);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        john.signForm(form3);
        john.executeForm(form3);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
