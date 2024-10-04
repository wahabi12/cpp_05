/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 02:57:17 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 03:19:48 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl; 
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl; 
        // Cette ligne devrait lancer une exception
        john.incrementGrade();
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat jane("Jane", 150);
        std::cout << jane << std::endl;
        // Cette ligne devrait lancer une exception
        jane.decrementGrade();
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
