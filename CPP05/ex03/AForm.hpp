/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:44:39 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 11:44:41 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const	name;
	bool				sign;
	int const			gradeToSign;
	int const			gradeToExecute;
public:
	AForm();
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &form);
	virtual ~AForm();
	AForm &operator=(AForm const &form);
	std::string const &getName() const;
	bool	getSign() const;
	int 	getGradeToSign() const;
	int 	getGradeToExecute() const;
	void	beSigned(Bureaucrat const &bureaucrat);
	virtual void	execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
