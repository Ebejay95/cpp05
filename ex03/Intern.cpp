/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:42:07 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/12/04 18:07:25 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
	return *this;
}

Intern::~Intern() {}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form type not found!";
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	const std::string formTypes[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* (Intern::*formCreators[])(const std::string&) const = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i]) {
			AForm* form = (this->*formCreators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	throw FormNotFoundException();
}