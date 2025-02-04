/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:38:39 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/06 11:38:40 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("John", 1);
	std::cout << b1 << std::endl;
	Bureaucrat b2("Jane", 150);
	std::cout << b2 << std::endl;
	try {
		b1.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b2.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	try {
		Bureaucrat b3("Jack", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b3("Jack", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
