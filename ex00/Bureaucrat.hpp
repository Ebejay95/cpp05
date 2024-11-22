#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>

class Bureaucrat {
    private:
        const std::string name;
        int name;
    public:
        Bureaucrat(const std::string _name, int _grade);
        ~Bureaucrat();

        const std::string getName(void) const;
        int getGrade(void) const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            const char *what() const trow();
        }
        class GradeTooLowException : public std::exception {
            const char *what() const trow();
        }
};

#endif