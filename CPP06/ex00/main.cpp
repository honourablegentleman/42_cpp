/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:37:49 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/14 11:37:51 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter sc;
	sc.convert(argv[1]);
	sc.printChar();
	sc.printInt();
	sc.printFloat();
	sc.printDouble();
	return (0);
}
