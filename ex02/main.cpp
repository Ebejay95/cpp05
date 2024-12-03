/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:05:59 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/03 13:48:46 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

void testShrubberyCreation() {
	std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat highLevel("HighLevel", 1);
		Bureaucrat lowLevel("LowLevel", 150);
		ShrubberyCreationForm form("garden");

		// Test without signing
		std::cout << "\nTrying to execute without signing:" << std::endl;
		highLevel.executeForm(form);

		// Test signing with too low grade
		std::cout << "\nTrying to sign with low grade:" << std::endl;
		lowLevel.signForm(form);

		// Test proper signing and execution
		std::cout << "\nProper signing and execution:" << std::endl;
		highLevel.signForm(form);
		highLevel.executeForm(form);

		// Test execution with too low grade
		std::cout << "\nTrying to execute with low grade:" << std::endl;
		lowLevel.executeForm(form);
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testRobotomyRequest() {
	std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
	try {
		Bureaucrat highLevel("HighLevel", 1);
		RobotomyRequestForm form("Target");

		// Test proper signing and multiple executions
		std::cout << "\nProper signing and multiple executions:" << std::endl;
		highLevel.signForm(form);
		for (int i = 0; i < 5; i++) {
			highLevel.executeForm(form);
		}
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testPresidentialPardon() {
	std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat mediumLevel("MediumLevel", 20);
		Bureaucrat highLevel("HighLevel", 1);
		PresidentialPardonForm form("Criminal");

		// Test signing with sufficient grade but execution with insufficient grade
		std::cout << "\nSigning with medium grade:" << std::endl;
		mediumLevel.signForm(form);
		std::cout << "\nTrying to execute with medium grade:" << std::endl;
		mediumLevel.executeForm(form);

		// Test proper execution
		std::cout << "\nProper execution with high grade:" << std::endl;
		highLevel.executeForm(form);
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testCopyAndAssignment() {
	std::cout << "\n=== Testing Copy and Assignment ===" << std::endl;
	try {
		ShrubberyCreationForm form1("garden1");
		ShrubberyCreationForm form2 = form1; // Copy constructor
		ShrubberyCreationForm form3("garden3");
		form3 = form1; // Assignment operator

		Bureaucrat bureaucrat("John", 1);
		bureaucrat.signForm(form1);

		std::cout << "\nOriginal form: " << form1 << std::endl;
		std::cout << "Copied form: " << form2 << std::endl;
		std::cout << "Assigned form: " << form3 << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	testShrubberyCreation();
	testRobotomyRequest();
	testPresidentialPardon();
	testCopyAndAssignment();

	std::cout << "\n=== Testing Edge Cases ===" << std::endl;
	try {
		// Test with invalid grades
		ShrubberyCreationForm invalidForm1("invalid");
		RobotomyRequestForm invalidForm2("invalid");
		PresidentialPardonForm invalidForm3("invalid");

		Bureaucrat superLow("SuperLow", 150);
		Bureaucrat superHigh("SuperHigh", 1);

		// Test multiple operations
		superLow.signForm(invalidForm1);
		superLow.executeForm(invalidForm1);
		superHigh.signForm(invalidForm1);
		superHigh.executeForm(invalidForm1);
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}