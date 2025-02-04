/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:57:38 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 13:57:39 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &intern)
{
	if (this == &intern)
		return *this;
	return *this;
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			for (int j = 0; j < 3; j++)
				if (j != i)
					delete forms[j];
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i];
		}
	}
	for (int i = 0; i < 3; i++)
		delete forms[i];
	std::cout << "Intern can't create " << formName << std::endl;
	return NULL;
}
