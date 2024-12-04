/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:23:57 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/04 18:02:42 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
	: AForm("Shrubbery Creation", 145, 137), target(_target) {}

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