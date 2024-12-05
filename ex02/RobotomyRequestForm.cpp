/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:20:31 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/05 13:29:30 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::initialized = false;

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), target("default") {
	if (!initialized) {
		srand(time(NULL));
		initialized = true;
	}
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
	: AForm("Robotomy Request", 72, 45), target(_target) {
	if (!initialized) {
		srand(time(NULL));
		initialized = true;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) { }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecutePermission(executor);
	std::cout << "* drilling noises *" << std::endl;

	if (rand() % 100 < 50) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomization of " << target << " failed." << std::endl;
	}
}