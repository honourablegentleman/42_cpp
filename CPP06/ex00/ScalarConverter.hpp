/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:28:00 by jhoddy            #+#    #+#             */
/*   Updated: 2025/01/14 11:28:02 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <limits>

#define ERROR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define INF 5
#define IS_NAN 6
#define INFF 7

class ScalarConverter
{
private:
	int		type;
	int		i;
	float	f;
	double	d;
	char	c;
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);
	void	convert(const std::string &str);
	int		checkType(const std::string &str);
	void	convertChar(const std::string &str);
	void	convertInt(const std::string &str);
	void	convertFloat(const std::string &str);
	void	printChar();
	void	printInt();
	void	printFloat();
	void	printDouble();
	int		getType() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;
	char	getChar() const;
};

#endif
