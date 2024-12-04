/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:39:59 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/12/04 18:07:37 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./Intern.hpp"

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

void testIntern() {
	std::cout << "\n=== Testing Intern ===" << std::endl;

	Intern intern;
	Bureaucrat boss("Boss", 1);

	try {
		// Test valid form creation
		AForm* form1 = intern.makeForm("robotomy request", "Bender");
		if (form1) {
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}

		// Test presidential pardon form
		AForm* form2 = intern.makeForm("presidential pardon", "Criminal");
		if (form2) {
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}

		// Test shrubbery creation form
		AForm* form3 = intern.makeForm("shrubbery creation", "Garden");
		if (form3) {
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}

		// Test invalid form name
		AForm* form4 = intern.makeForm("invalid form", "Target");
		if (form4) {
			delete form4;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	testShrubberyCreation();
	testRobotomyRequest();
	testPresidentialPardon();
	testCopyAndAssignment();
	testIntern();

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