/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:05:34 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 11:05:36 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					value;
	static const int	raw_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed	&operator=(const Fixed &fixed);
	bool	operator>(const Fixed &fixed) const;
	bool	operator<(const Fixed &fixed) const;
	bool	operator<=(const Fixed &fixed) const;
	bool	operator>=(const Fixed &fixed) const;
	bool	operator==(const Fixed &fixed) const;
	bool	operator!=(const Fixed &fixed) const;
	float	operator+(const Fixed &fixed) const;
	float	operator-(const Fixed &fixed) const;
	float	operator*(const Fixed &fixed) const;
	float	operator/(const Fixed &fixed) const;
	Fixed	operator++();
	Fixed	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed&		min(Fixed &n1, Fixed &n2);
	static const Fixed&	min(const Fixed &n1, const Fixed &n2);
	static Fixed&		max(Fixed &n1, Fixed &n2);
	static const Fixed&	max(const Fixed &n1, const Fixed &n2);
};

std::ostream&	operator << (std::ostream &out, const Fixed &fixed);

#endif
