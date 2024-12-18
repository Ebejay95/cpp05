/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:02 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/04 11:34:39 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main() {
	try {
		// Test form creation and basic attributes
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;

		// Test signing with valid bureaucrat
		Bureaucrat b1("John", 40);
		b1.signForm(f1);
		std::cout << f1 << std::endl;

		// Test signing with invalid bureaucrat
		Bureaucrat b2("Mike", 100);
		b2.signForm(f1);

		// Test form with invalid grades
		Form f2("Invalid Form", 0, 25);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Form f3("Another Invalid Form", 151, 25);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test copy constructor and assignment operator
	try {
		Form f4("Original Form", 50, 25);
		Form f5(f4);  // Copy constructor
		Form f6 = f4; // Assignment operator

		std::cout << "Original: " << f4 << std::endl;
		std::cout << "Copy: " << f5 << std::endl;
		std::cout << "Assigned: " << f6 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Form f("Test Form", 50, 25);
		Bureaucrat b1("High Grade", 1);
		b1.signForm(f);
		b1.signForm(f);
		std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Form f1("Edge Form", 1, 150);
		Bureaucrat b1("Max Grade", 1);
		Bureaucrat b2("Min Grade", 150);
		b1.signForm(f1);
		b2.signForm(f1);
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}