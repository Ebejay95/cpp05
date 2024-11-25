/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:04 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/11/25 09:19:23 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string _name, int _grade);
        ~Bureaucrat();

        const std::string getName(void) const;
        int getGrade(void) const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
			const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
			const char* what() const throw();
        };
	
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

};

#endif