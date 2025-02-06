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
	this->type = src.type;
	this->i = src.i;
	this->f = src.f;
	this->d = src.d;
	this->c = src.c;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	this->i = src.i;
	this->f = src.f;
	this->d = src.d;
	this->c = src.c;
	return (*this);
}

int	ScalarConverter::checkType(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);
	else if (str.find_first_not_of("+-0123456789") == std::string::npos
			&& (str.find_last_of("+-") == 0 || str.find_last_of("+-") == std::string::npos)
			&& str.length() < 11
			&& std::atol(str.c_str()) <= std::numeric_limits<int>::max()
			&& std::atol(str.c_str()) >= std::numeric_limits<int>::min())
		return (INT);
	else if (str.find_first_not_of("+-0123456789.f") == std::string::npos
			&& str.find('f') == str.rfind('f')
			&& (str.find_last_of("+-") == 0 || str.find_last_of("+-") == std::string::npos)
			&& str.find('.') != std::string::npos
			&& str.find('.') == str.rfind('.'))
		return (FLOAT);
	else if (str.find_first_not_of("+-0123456789.e") == std::string::npos
			&& str.find('e') == str.find_first_of('e')
			&& (str.find_last_of("+-") == 0 || str.find_last_of("+-") == std::string::npos)
			&& str.find('.') == str.rfind('.')
			&& str.find('.') != std::string::npos)
		return (DOUBLE);
	else if (str == "nan" || str == "nanf" || str == "+nan" || str == "-nan" || str == "+nanf" || str == "-nanf")
		return (IS_NAN);
	else if (str == "-inf" || str == "+inf" || str == "inf" || str == "-inff" || str == "+inff" || str == "inff")
		return (INF);
	else
		return (ERROR);
}

void	ScalarConverter::convert(const std::string &str)
{
	this->input = str;
	this->type = checkType(str);
	if (this->type == CHAR)
		convertChar(str);
	else if (this->type == INT)
		convertInt(str);
	else if (this->type == FLOAT || this->type == DOUBLE)
		convertFloat(str);
}

void	ScalarConverter::convertChar(const std::string &str)
{
	this->c = str[0];
	this->i = static_cast<int>(c);
	this->f = static_cast<float>(c);
	this->d = static_cast<double>(c);
}

void	ScalarConverter::convertInt(const std::string &str)
{
	this->i = static_cast<int>(std::atoi(str.c_str()));
	this->c = static_cast<char>(i);
	this->f = static_cast<float>(i);
	this->d = static_cast<double>(i);
}

void	ScalarConverter::convertFloat(const std::string &str)
{
	this->f = static_cast<float>(std::atof(str.c_str()));
	this->i = static_cast<int>(f);
	this->d = static_cast<double>(f);
	this->c = static_cast<char>(f);
}

void	ScalarConverter::printChar()
{
	if (this->type == ERROR || this->type == IS_NAN)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else if ((this->type == INT || this->type == FLOAT || this->type == DOUBLE) && (this->i >= 32 && this->i <= 127))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else if (this->type == CHAR)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void	ScalarConverter::printInt()
{
	if (this->type == IS_NAN || this->type == INF || this->type == ERROR)
		std::cout << "int: impossible" << std::endl;
	else if (this->type == CHAR)
		std::cout << "int: " << static_cast<int>(c) << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printFloat()
{
	if (this->type == IS_NAN)
	{
		if (this->input == "nan" || this->input == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (this->input[0] == '+')
			std::cout << "float: +nanf" << std::endl;
		else if (this->input[0] == '-')
			std::cout << "float: -nanf" << std::endl;
	}
	else if (this->type == INF)
		std::cout << "float: inff" << std::endl;
	else if (this->type == ERROR)
		std::cout << "float: impossible" << std::endl;
	else if (this->type == INT || f - i == 0 || this->type == CHAR)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void	ScalarConverter::printDouble()
{
	if (this->type == IS_NAN)
	{
		if (this->input == "nan" || this->input == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (this->input[0] == '+')
			std::cout << "double: +nan" << std::endl;
		else if (this->input[0] == '-')
			std::cout << "double: -nan" << std::endl;
	}
	else if (this->type == INF)
		std::cout << "double: inf" << std::endl;
	else if (this->type == ERROR)
		std::cout << "double: impossible" << std::endl;
	else if (this->type == INT || d - i == 0 || this->type == CHAR)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

int	ScalarConverter::getType() const
{
	return (this->type);
}

int	ScalarConverter::getInt() const
{
	return (this->i);
}

float	ScalarConverter::getFloat() const
{
	return (this->f);
}

double	ScalarConverter::getDouble() const
{
	return (this->d);
}

char	ScalarConverter::getChar() const
{
	return (this->c);
}
