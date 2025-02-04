/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:52:58 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/13 11:53:00 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm) : AForm(shrubberyCreationForm)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm)
{
	if (this == &shrubberyCreationForm)
		return *this;
	AForm::operator=(shrubberyCreationForm);
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	std::ofstream	file;
	std::string	name = executor.getName() + "_shrubbery";
	file.open(name.c_str(), std::ios::out);
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\n";
	file << "  ni" << std::endl;
	file.close();
}
