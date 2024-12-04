/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:38:39 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/12/04 11:38:41 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

AForm::AForm() :
	name("default"),
	is_signed(false),
	required_sign_grade(150),
	required_exec_grade(150) {}

AForm::AForm(const std::string _name, int _rsg, int _reg) :
	name(_name),
	is_signed(false),
	required_sign_grade(_rsg),
	required_exec_grade(_reg)
{
	if (_rsg < 1 || _reg < 1)
		throw AForm::GradeTooHighException();
	if (_rsg > 150 || _reg > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	name(other.name),
	is_signed(other.is_signed),
	required_sign_grade(other.required_sign_grade),
	required_exec_grade(other.required_exec_grade) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		is_signed = other.is_signed;
	}
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName(void) const {
	return name;
}

bool AForm::getIsSigned(void) const {
	return is_signed;
}

int AForm::getRequiredSignGrade(void) const {
	return required_sign_grade;
}

int AForm::getRequiredExecGrade(void) const {
	return required_exec_grade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > required_sign_grade)
		throw AForm::GradeTooLowException();
	is_signed = true;
}

void AForm::checkExecutePermission(Bureaucrat const & executor) const {
	if (!is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > required_exec_grade)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form " << form.getName()
	<< ", sign grade " << form.getRequiredSignGrade()
	<< ", exec grade " << form.getRequiredExecGrade()
	<< ", signed: " << (form.getIsSigned() ? "yes" : "no");
	return os;
}