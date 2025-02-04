/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:28:21 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/06 13:28:57 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	name;
	bool				sign;
	int const			gradeToSign;
	int const			gradeToExecute;
public:
	Form();
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(Form const &form);
	~Form();
	Form &operator=(Form const &form);
	std::string const &getName() const;
	bool	getSign() const;
	int 	getGradeToSign() const;
	int 	getGradeToExecute() const;
	void	beSigned(Bureaucrat const &bureaucrat);
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
