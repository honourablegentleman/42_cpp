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
	{
		std::cout << "Normal creation:\n" << std::endl;
		try {
			Form	f1("Form1", 1, 1);
			std::cout << f1 << std::endl;
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		try {
			Form f2("Form2", 150, 150);
			std::cout << f2 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------------------" << std::endl;
		std::cout << "Too low/too high creation:\n" << std::endl;
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
	}
	{
		std::cout << "-----------------------------" << std::endl;
		std::cout << "Sign test:\n" << std::endl;
		Form		f4("Form4", 100, 90);
		Form		f5(f4);

		Bureaucrat	b1;
		std::cout << b1 << std::endl;
		b1.signForm(f4);
		std::cout << f4 << std::endl;

		Bureaucrat	b2("Dave", 100);
		std::cout << b2 << std::endl;
		b2.signForm(f5);
		std::cout << f5 << std::endl;
	}
	return (0);
}
