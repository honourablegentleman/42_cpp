/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:38:24 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/06 11:38:29 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
	std::string const	name;
	int 				grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &bureaucrat);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &bureaucrat);
	std::string const &getName() const;
	int 	getGrade() const;
	void	setGrade(int grade);
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	void	incrementGrade();
	void	decrementGrade();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
