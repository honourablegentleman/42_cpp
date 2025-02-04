/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:05:44 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 11:05:46 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->raw_bits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << this->raw_bits));
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator = (const Fixed &fixed)
{
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(const Fixed &fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(const Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(const Fixed &fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(const Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->value--;
	return (tmp);
}

int	Fixed::getRawBits() const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat() const
{
	return (roundf(this->value) / (1 << this->raw_bits));
}

int	Fixed::toInt() const
{
	return (this->value >> this->raw_bits);
}

Fixed&	Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

const Fixed&	Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

Fixed&	Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

const Fixed&	Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

std::ostream&	operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
