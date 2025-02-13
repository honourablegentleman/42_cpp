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

void	ShrubberyCreationForm::activateForm(const Bureaucrat &executor) const
{
	std::ofstream	file;
	std::string	name = executor.getName() + "_shrubbery";
	file.open(name.c_str(), std::ios::out);
	file << "                     .o00o                             .--.\n";
	file << "                   o000000oo                          /.--.\\\n";
	file << "                  00000000000o                  (ni)  |====|\n";
	file << "                 00000000000000                       |`::`|\n";
	file << "              oooooo  00000000  o88o              .-;`\\..../`;-.\n";
	file << "           ooOOOOOOOoo  ```''  888888            /  |...::...|  \\\n";
	file << "         OOOOOOOOOOOO'.qQQQQq. `8888'           |   /'''::'''\\   |\n";
	file << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'            ;--'\\   ::   /\\--;\n";
	file << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q              <__>,>._::_.<,<__>\n";
	file << "         OOOOOOOOO QQQQQQQQQQ/ /QQ              |  |/   ^^   \\|  |\n";
	file << "           OOOOOOOOO `QQQQQQ/ /QQ'              \\::/|        |\\::/\n";
	file << "             OO:F_P:O `QQQ/  /Q'                |||\\|        |/|||\n";
	file << "                \\\\. \\ |  // |                   ''' |___/\\___| '''\n";
	file << "                d\\ \\\\\\|_////                         \\_ || _/\n";
	file << "                qP| \\\\ _' `|Ob                       <_ >< _>\n";
	file << "                   \\  / \\  \\Op                       |  ||  |\n";
	file << "                   |  | O| |                         |  ||  |\n";
	file << "           _       /\\. \\_/ /\\                       _\\.:||:./_\n";
	file << "            `---__/|_\\\\   //|  __                  /____/\\____\\\n";
	file << "                  `-'  `-'`-'-'\n";
	file.close();
}
