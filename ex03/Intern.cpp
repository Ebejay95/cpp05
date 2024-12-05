/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:42:07 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/12/05 13:18:39 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form type not found!";
}

AForm* Intern::createPresidentialPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequest(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreation(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	static const FormType forms[] = {
		{"presidential pardon", &createPresidentialPardon},
		{"robotomy request", &createRobotomyRequest},
		{"shrubbery creation", &createShrubberyCreation}
	};
	static const int formCount = 3;

	for (int i = 0; i < formCount; i++) {
		if (formName == forms[i].name) {
			AForm* form = forms[i].creator(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	throw FormNotFoundException();
}