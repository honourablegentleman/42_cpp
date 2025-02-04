/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:53:49 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 11:53:51 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm) : AForm(robotomyRequestForm)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
	if (this == &robotomyRequestForm)
		return *this;
	AForm::operator=(robotomyRequestForm);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	std::cout << " * loud drilling noises * " << std::endl;
	if (rand() % 2)
		std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << executor.getName() << " robotomization failed" << std::endl;
}
