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
	{
		std::cout << "Shrubbery form test:\n" << std::endl;
		ShrubberyCreationForm	shrub_form("Shrubbery");
		Bureaucrat				b1("King Arthur", 1);
		b1.executeForm(shrub_form);
		b1.signForm(shrub_form);
		b1.executeForm(shrub_form);
		Bureaucrat				b2("Sir Not-appearing-in-this-film", 140);
		b2.executeForm(shrub_form);
	}
	{
		std::cout << "-----------------------------" << std::endl;
		std::cout << "Robot form test:\n" << std::endl;
		RobotomyRequestForm		robot("Robot");
		Bureaucrat				b3("Dr Eggman", 1);
		b3.executeForm(robot);
		b3.signForm(robot);
		b3.executeForm(robot);
		Bureaucrat				b4("Sonic", 100);
		b4.executeForm(robot);
	}
	{
		std::cout << "-----------------------------" << std::endl;
		std::cout << "Pardon form test:\n" << std::endl;
		PresidentialPardonForm	pardon("Pardon");
		Bureaucrat				b5("Biden", 1);
		b5.executeForm(pardon);
		b5.signForm(pardon);
		b5.executeForm(pardon);
		Bureaucrat				b6("Reagan", 40);
		b6.executeForm(pardon);
	}
	return (0);
}
