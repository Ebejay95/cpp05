/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:22:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/04 17:51:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form() :
	name("default"),
	is_signed(false),
	required_sign_grade(150),
	required_exec_grade(150) {}

Form::Form(const std::string _name, int _rsg, int _reg) :
	name(_name),
	is_signed(false),
	required_sign_grade(_rsg),
	required_exec_grade(_reg)
{
	if (_rsg < 1 || _reg < 1)
		throw Form::GradeTooHighException();
	if (_rsg > 150 || _reg > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) :
	name(other.name),
	is_signed(other.is_signed),
	required_sign_grade(other.required_sign_grade),
	required_exec_grade(other.required_exec_grade) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		is_signed = other.is_signed;
	}
	return *this;
}

Form::~Form() {}

const std::string Form::getName(void) const {
	return name;
}

bool Form::getIsSigned(void) const {
	return is_signed;
}

int Form::getRequiredSignGrade(void) const {
	return required_sign_grade;
}

int Form::getRequiredExecGrade(void) const {
	return required_exec_grade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (is_signed)
		throw Form::AlreadySignedException();
	if (bureaucrat.getGrade() > required_sign_grade)
		throw Form::GradeTooLowException();
	is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "Form is already signed!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName()
	<< ", sign grade " << form.getRequiredSignGrade()
	<< ", exec grade " << form.getRequiredExecGrade()
	<< ", signed: " << (form.getIsSigned() ? "yes" : "no");
	return os;
}