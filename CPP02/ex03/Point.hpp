/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:01:30 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 13:01:33 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point();
	Point(const Point &point);
	Point(const float x, const float y);
	~Point();
	Point	&operator=(const Point &point);
	bool	operator==(const Point &point) const;
	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Point &point);
float	calculate_area(Point const &p1, Point const &p2, Point const &p3);
bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif
