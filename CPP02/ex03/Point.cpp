/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:01:41 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 13:01:47 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &point)
{
	*this = point;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point &point)
{
	if (this == &point)
		return (*this);
	return (*this);
}

bool	Point::operator==(const Point &point) const
{
	return (this->x == point.x && this->y == point.y);
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}

std::ostream&	operator<<(std::ostream &out, const Point &point)
{
	out << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (out);
}
