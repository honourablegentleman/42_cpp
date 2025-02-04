/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:05:28 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 14:05:31 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main()
{
	Intern	intern;
	AForm	*form1 = intern.makeForm("shrubbery creation", "home");
	AForm	*form2 = intern.makeForm("robotomy request", "robot");
	AForm	*form3 = intern.makeForm("presidential pardon", "sir");
	AForm	*form4 = intern.makeForm("true", "lord");
	Bureaucrat	bureaucrat("Dave", 1);
	bureaucrat.signForm(*form1);
	bureaucrat.executeForm(*form1);
	bureaucrat.signForm(*form2);
	bureaucrat.executeForm(*form2);
	bureaucrat.signForm(*form3);
	bureaucrat.executeForm(*form3);
	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return (0);
}
