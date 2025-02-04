/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:38:12 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/06 11:38:15 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	if (this == &bureaucrat)
		return *this;
	this->grade = bureaucrat.grade;
	return *this;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::string const	&Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

void	Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &e) {
		std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::incrementGrade()
{
	this->setGrade(this->grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	this->setGrade(this->grade + 1);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
