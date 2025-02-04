/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:17:44 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 13:17:47 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int	main()
{
	AForm		*form = new ShrubberyCreationForm("home");
	Bureaucrat	bureaucrat("Dave", 1);
	bureaucrat.executeForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
	AForm		*form2 = new RobotomyRequestForm("robot");
	Bureaucrat	bureaucrat2("Phil", 1);
	bureaucrat.executeForm(*form2);
	bureaucrat.signForm(*form2);
	bureaucrat.executeForm(*form2);
	delete form2;
	AForm		*form3 = new PresidentialPardonForm("sir");
	Bureaucrat	bureaucrat3("Bob", 1);
	bureaucrat.executeForm(*form3);
	bureaucrat.signForm(*form3);
	bureaucrat.executeForm(*form3);
	delete form3;
}
