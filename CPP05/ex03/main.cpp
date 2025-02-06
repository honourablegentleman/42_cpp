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
	std::cout << "Intern test:\n" << std::endl;
	Intern	intern;
	AForm	*form1 = intern.makeForm("shrubbery creation", "Shrubbery");
	AForm	*form2 = intern.makeForm("robotomy request", "Robot");
	AForm	*form3 = intern.makeForm("presidential pardon", "Pardon");
	AForm	*form4 = intern.makeForm("true", "lord");
	std::cout << std::endl;

	std::cout << form1->getName() << std::endl;
	std::cout << form2->getName() << std::endl;
	std::cout << form3->getName() << std::endl;

	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return (0);
}
