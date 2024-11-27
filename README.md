# C++ Module 05

**Repetition and Exceptions in C++**

This module introduces exception handling and advanced object-oriented concepts. The goal is to implement a bureaucratic system with various forms and roles.

## Structure

### ex00/ - Bureaucrat Basics
- **Bureaucrat.{hpp,cpp}**: Implementation of the Bureaucrat class
- **main.cpp**: Tests for constructors, getters, and exceptions (`GradeTooHighException`, `GradeTooLowException`)

### ex01/ - Form Management
- **Bureaucrat.{hpp,cpp}**: From ex00
- **Form.{hpp,cpp}**: Form class with signing and execution requirements
- **main.cpp**: Tests for form signing by bureaucrats and exceptions

### ex02/ - Specialized Forms
- **Bureaucrat.{hpp,cpp}**: From ex00
- **AForm.{hpp,cpp}**: Abstract base class for forms
- **ShrubberyCreationForm.{hpp,cpp}**: Generates ASCII trees
- **RobotomyRequestForm.{hpp,cpp}**: Robotomy with a 50% success rate
- **PresidentialPardonForm.{hpp,cpp}**: Grants a pardon from Zaphod Beeblebrox
- **main.cpp**: Tests for specialized forms and their execution

### ex03/ - Intern Integration
- **Intern.{hpp,cpp}**: Implementation of the Intern class
- **AForm** and specialized forms from ex02
- **main.cpp**: Tests for dynamic form creation by the Intern

## Features

- Exception handling: construction and error management
- Abstract base classes and specialization
- Dynamic memory management and exception safety
- Logical separation of signing and execution requirements
