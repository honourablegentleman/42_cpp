/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:23:40 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 13:23:42 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	calculate_area(Point const &p1, Point const &p2, Point const &p3)
{
	return (std::abs(p1.getX() * (p2.getY() - p3.getY())
					+ p2.getX() * (p3.getY() - p1.getY())
					+ p3.getX() * (p1.getY() - p2.getY())));
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	if (point == a || point == b || point == c)
		return (false);
	float	A = calculate_area(a, b, c);
	float	A1 = calculate_area(point, b, c);
	float	A2 = calculate_area(a, point, c);
	float	A3 = calculate_area(a, b, point);
	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);

	return (A == A1 + A2 + A3);
}
