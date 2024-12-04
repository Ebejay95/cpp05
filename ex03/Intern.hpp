/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:41:32 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/12/04 18:07:28 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		AForm* createPresidentialPardonForm(const std::string& target) const;
		AForm* createRobotomyRequestForm(const std::string& target) const;
		AForm* createShrubberyCreationForm(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif