/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:27:49 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/14 11:27:51 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

void	ScalarConverter::convert(const std::string &str)
{
	int	type = checkType(str);

	if (type == CHAR)
		printChar(str);
	else if (type == INT)
		printInt(str);
	else if (type == FLOAT)
		printFloat(str);
	else if (type == DOUBLE)
		printDouble(str);
	else
		printSpecial(str, type);
}

int	checkType(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);
	else if (str.find_first_not_of("+-0123456789") == std::string::npos
			&& (str.find_last_of("+-") == 0 || str.find_last_of("+-") == std::string::npos)
			&& str.length() < 11
			&& std::atol(str.c_str()) <= MAXINT && std::atol(str.c_str()) >= MININT)
		return (INT);
	else if (str.find_first_not_of("+-0123456789.f") == std::string::npos
			&& (str.find_last_of("+-") == std::string::npos || str.find_last_of("+-") == 0)
			&& ((str.find('.') != std::string::npos && str.find('.') == str.rfind('.')) || str.find('.') == std::string::npos)
			&& str.find('.') != 0
			&& std::atol(str.c_str()) <= MAXINT && std::atol(str.c_str()) >= MININT)
	{
		if (str.find('f') == std::string::npos)
			return (DOUBLE);
		else if (str.rfind('f') == str.length() - 1)
			return (FLOAT);
		else
			return (ERROR);
	}
	else if (str == "nan" || str == "nanf")
		return (IS_NAN);
	else if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff")
		return (INF);
	else
		return (ERROR);
}

void	printSpecial(const std::string &str, int type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == ERROR)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else if (type == IS_NAN)
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		if (str[0] == '+')
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
}

void	printChar(const std::string &str)
{
	char	c = str[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printInt(const std::string &str)
{
	int	i = static_cast<long>(std::atol(str.c_str()));

	std::cout << "char: ";
	if (i >= 32 && i <= 126)
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else if (i >= 0 && i <= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printFloat(const std::string &str)
{
	float	f = std::atof(str.c_str());
	int		prec = str.length() - str.find('.') - 2;

	if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (f >= 0 && f <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << static_cast<int>(f) << std::endl;

	if (prec == 5)
		std::cout << "float: " << std::fixed << std::setprecision(prec) << f;
	else
	{
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
	}
	std::cout << "f" << std::endl;

	if (prec == 5)
		std::cout << "double: " << std::fixed << std::setprecision(prec) << static_cast<double>(f);
	else
	{
		std::cout << "double: " << static_cast<double>(f);
		if (static_cast<double>(f) == static_cast<int>(f))
			std::cout << ".0";
	}
	std::cout << std::endl;
}

int	setfprec(std::string str)
{
	int	prec = str.length() - 1 - str.find('.');
	int	i = (prec < 4) ? prec : 4;
	int	stop = str.find('.') + 2;

	while (i > stop && str[i] == '0' && str[i] == '9')
		i--;
	if (i == stop)
		return (1);
	else
		return (i - stop);
}

void	printDouble(const std::string &str)
{
	double	d = std::atof(str.c_str());
	int		prec = str.length() - str.find('.') - 1;
	int		fprec = setfprec(str);

	if (d >= 32 && d <= 126)
		std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
	else if (d >= 0 && d <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (static_cast<float>(d) == static_cast<int>(d))
		std::cout << static_cast<float>(d) << ".0f" << std::endl;
	else if (prec > 4)
		std::cout << std::fixed << std::setprecision(fprec) << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;

	std::cout << "double: ";
	if (d == static_cast<int>(d))
		std::cout <<  d << ".0" << std::endl;
	else if (prec > 4 && prec < 14)
		std::cout <<  std::fixed << std::setprecision(prec) << d << std::endl;
	else if (prec > 14)
		std::cout << std::fixed << std::setprecision(14) << d << std::endl;
	else
		std::cout << d << std::endl;
}
