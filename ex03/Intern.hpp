/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:41:32 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/12/05 13:18:57 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {
private:
	struct FormType {
		std::string name;
		AForm* (*creator)(const std::string&);
	};

	static AForm* createPresidentialPardon(const std::string& target);
	static AForm* createRobotomyRequest(const std::string& target);
	static AForm* createShrubberyCreation(const std::string& target);

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;

	class FormNotFoundException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif