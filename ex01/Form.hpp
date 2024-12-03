/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:22:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/12/03 12:53:35 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FORM_HPP

# include <string>
# include <iostream>
# include "./Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to avoid circular dependency

class Form {
	private:
		const std::string name;
		bool is_signed;
		const int required_sign_grade;
		const int required_exec_grade;

	public:
		Form(); // Default constructor
		Form(const std::string _name, int _rsg, int _reg);
		Form(const Form& other); // Copy constructor
		Form& operator=(const Form& other); // Assignment operator
		~Form();

		const std::string getName(void) const;
		bool getIsSigned(void) const;
		int getRequiredSignGrade(void) const;
		int getRequiredExecGrade(void) const;
		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif