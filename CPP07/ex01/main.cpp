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

void	to_negative(int &i)
{
	if (i > 0)
		i *= -1;
	std::cout << i << " ";
}

void	times_two(float &i)
{
	i *= 2;
	std::cout << i << " ";
}

void	to_upper(char &i)
{
	i = std::toupper(i);
	std::cout << i << " ";
}

void	str_to_upper(std::string &i)
{
	for (size_t j = 0; j < i.size(); j++)
		i[j] = std::toupper(i[j]);
	std::cout << i << " ";
}

template <typename E>
void	print_array(E &i)
{
	std::cout << i << " ";
}

int	main()
{
	int		intArray[5] = {1, 2, 3, 4, 5};
	float	floatArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	charArray[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string	strArray[5] = {"this", "is", "very", "true", "yes"};

	std::cout << "intArray: " << std::endl;
	iter(intArray, 5, print_array);
	std::cout << std::endl;
	iter(intArray, 5, to_negative);
	std::cout << std::endl;

	std::cout << "floatArray: " << std::endl;
	iter(floatArray, 5, print_array);
	std::cout << std::endl;
	iter(floatArray, 5, times_two);
	std::cout << std::endl;

	std::cout << "charArray: " << std::endl;
	iter(charArray, 5, print_array);
	std::cout << std::endl;
	iter(charArray, 5, to_upper);
	std::cout << std::endl;

	std::cout << "strArray: " << std::endl;
	iter<std::string>(strArray, 5, print_array);
	std::cout << std::endl;
	iter(strArray, 5, str_to_upper);
	std::cout << std::endl;

	return 0;
}
