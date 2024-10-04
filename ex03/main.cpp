#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern intern;
    AForm* form;

    form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("shrubbery creation", "home");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("presidential pardon", "Arthur Dent");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("unknown form", "target");  // Formulaire inconnu
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    return 0;
}
