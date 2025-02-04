/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:27:29 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/06 13:27:33 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main()
{
	Form f1("Form1", 1, 1);
	std::cout << f1 << std::endl;
	Form f2("Form2", 150, 150);
	std::cout << f2 << std::endl;
	try {
		Form f3("Form3", 0, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f3("Form3", 1, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f3("Form3", 151, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f3("Form3", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Form f4("Form4", 100, 90);
	Bureaucrat b1;
	Bureaucrat b2("John", 100);
	b1.signForm(f4);
	b2.signForm(f4);
	return (0);
}
