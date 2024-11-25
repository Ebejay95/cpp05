/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:02 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/11/25 09:19:16 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        Bureaucrat high("High", 0);
        std::cout << high << std::endl;
    }
	catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Low", 151);
        std::cout << low << std::endl;
    }
	catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

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

    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
    }
	catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
    }
	catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
