/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:23:03 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/04 03:40:23 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        Bureaucrat jane("Jane", 150);

        Form form1("Form1", 1, 10);
        Form form2("Form2", 100, 120);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        john.signForm(form1);  // John ne peut pas signer, grade insuffisant
        john.signForm(form2);  // John peut signer form2

        jane.signForm(form1);  // Jane ne peut pas signer form1, grade trop bas
        jane.signForm(form2);  // Jane peut signer form2
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
