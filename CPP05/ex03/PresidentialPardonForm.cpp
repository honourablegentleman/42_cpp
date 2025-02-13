/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:53:26 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 12:06:26 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm) : AForm(presidentialPardonForm)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
	if (this == &presidentialPardonForm)
		return *this;
	AForm::operator=(presidentialPardonForm);
	return *this;
}

void	PresidentialPardonForm::activateForm(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
