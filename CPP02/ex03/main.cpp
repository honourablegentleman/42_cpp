/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:59:42 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 13:59:43 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	tests(Point const &a, Point const &b, Point const &c, Point const &p)
{
	std::cout << "\np = " << p << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "p is inside the triangle" << std::endl;
	else
		std::cout << "p is outside the triangle" << std::endl;
}

int	main()
{
	Point	a(0, 0);
	Point	b(0, 4);
	Point	c(4, 0);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	tests(a, b, c, Point(1, 1));
	tests(a, b, c, Point(5, 5));
	tests(a, b, c, Point(-2, -2));
	tests(a, b, c, Point(0, 0));
	tests(a, b, c, Point(2, 2));
	return (0);
}
