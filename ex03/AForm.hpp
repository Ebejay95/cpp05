/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:39:44 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/12/04 11:39:46 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool is_signed;
		const int required_sign_grade;
		const int required_exec_grade;

	public:
		AForm();
		AForm(const std::string _name, int _rsg, int _reg);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string getName(void) const;
		bool getIsSigned(void) const;
		int getRequiredSignGrade(void) const;
		int getRequiredExecGrade(void) const;
		void beSigned(const Bureaucrat& bureaucrat);

		virtual void execute(Bureaucrat const & executor) const = 0;
		void checkExecutePermission(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif