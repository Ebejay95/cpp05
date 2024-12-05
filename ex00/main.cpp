/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:59:31 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/05 11:20:12 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main() {

	std::cout << "\n=== Testing default constructor ===" << std::endl;
	try {
		Bureaucrat default_bureaucrat;
		std::cout << "Default bureaucrat: " << default_bureaucrat << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "=== Testing basic constructor and operators ===" << std::endl;
	try {
		Bureaucrat john("John", 50);
		std::cout << john << std::endl;

		Bureaucrat johnCopy(john);
		std::cout << "Copy of John: " << johnCopy << std::endl;

		Bureaucrat assignedJohn = john;
		std::cout << "Assigned copy of John: " << assignedJohn << std::endl;

		johnCopy.incrementGrade();
		std::cout << "Original John: " << john << std::endl;
		std::cout << "Modified copy: " << johnCopy << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing grade too high exception ===" << std::endl;
	try {
		Bureaucrat high("High", 0);
		std::cout << high << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing grade too low exception ===" << std::endl;
	try {
		Bureaucrat low("Low", 151);
		std::cout << low << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing increment/decrement ===" << std::endl;
	try {
		Bureaucrat mike("Mike", 10);
		std::cout << mike << std::endl;
		mike.incrementGrade();
		std::cout << "After increment: " << mike << std::endl;

		mike.decrementGrade();
		mike.decrementGrade();
		std::cout << "After two decrements: " << mike << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing edge cases ===" << std::endl;
	try {
		// Test grade 1 (highest possible)
		Bureaucrat top("Top", 1);
		std::cout << "Created bureaucrat with grade 1: " << top << std::endl;
		std::cout << "Attempting to increment grade 1..." << std::endl;
		top.incrementGrade();
		std::cout << "Updated bureaucrat with grade 1: " << top << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


	try {
		// Test grade 150 (lowest possible)
		Bureaucrat bottom("Bottom", 150);
		std::cout << "Created bureaucrat with grade 150: " << bottom << std::endl;
		std::cout << "Attempting to decrement grade 150..." << std::endl;
		bottom.decrementGrade();
		std::cout << "Updated bureaucrat with grade 150: " << bottom << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}