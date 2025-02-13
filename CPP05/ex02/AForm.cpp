/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:44:23 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 11:49:37 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), sign(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &form) : name(form.name), sign(form.sign), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(AForm const &form)
{
	if (this == &form)
		return *this;
	this->sign = form.sign;
	return *this;
}

std::string const	&AForm::getName() const
{
	return this->name;
}

bool	AForm::getSign() const
{
	return this->sign;
}

int	AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	activateForm(executor);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSign())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return out;
}
