/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:23:57 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/03 13:32:05 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.cpp
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkExecutePermission(executor);

	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file");

	file << "       _-_" << std::endl;
	file << "      // \\\\" << std::endl;
	file << "     //   \\\\" << std::endl;
	file << "    //     \\\\" << std::endl;
	file << "   //       \\\\" << std::endl;
	file << "  //         \\\\" << std::endl;
	file << " //           \\\\" << std::endl;
	file << "//             \\\\" << std::endl;
	file << "      |||" << std::endl;
	file << "      |||" << std::endl;
	file << "      |||" << std::endl;

	file.close();
}