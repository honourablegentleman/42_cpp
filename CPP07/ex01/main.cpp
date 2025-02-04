/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:46:33 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 13:46:36 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	foo(int const &i)
{
	std::cout << i << " ";
	return 0;
}

float bar(float const &i)
{
	std::cout << i << " ";
	return 0;
}

char	foobar(char const &i)
{
	std::cout << i << " ";
	return 0;
}

int	main()
{
	int		intArray[5] = {1, 2, 3, 4, 5};
	float	floatArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	charArray[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "intArray: ";
	iter(intArray, 5, foo);
	std::cout << std::endl;

	std::cout << "floatArray: ";
	iter(floatArray, 5, bar);
	std::cout << std::endl;

	std::cout << "charArray: ";
	iter(charArray, 5, foobar);
	std::cout << std::endl;

	return 0;
}
