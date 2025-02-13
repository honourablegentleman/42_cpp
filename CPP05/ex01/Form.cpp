/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:29:04 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/07 12:24:50 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), sign(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &form) : name(form.name), sign(form.sign), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
}

Form::~Form()
{
}

Form	&Form::operator=(Form const &form)
{
	if (this == &form)
		return *this;
	this->sign = form.sign;
	return *this;
}

std::string const	&Form::getName() const
{
	return this->name;
}

bool	Form::getSign() const
{
	return this->sign;
}

int	Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSign())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to activateForm";
	return out;
}
