/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeberle <joeberle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:27:09 by jeberle           #+#    #+#             */
/*   Updated: 2024/11/22 21:27:58 by joeberle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name) {
    if (grade <= 1)
        trow GradeTooHighException();
    if (grade >= 150)
        trow GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName(void) const {
    return name;
}
int Bureaucrat::getGrade(void) const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}