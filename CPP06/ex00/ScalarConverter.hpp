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

#define MAX_INT std::numeric_limits<int>::max()
#define MIN_INT std::numeric_limits<int>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_DOUBLE std::numeric_limits<double>::max()
#define MIN_DOUBLE std::numeric_limits<double>::min()

#define ERROR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define INF 5
#define IS_NAN 6

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
public:
	~ScalarConverter();
	static void	convert(const std::string &str);
};

int		checkType(const std::string &str);
void	printChar(const std::string &str);
void	printInt(const std::string &str);
void	printFloat(const std::string &str);
void	printDouble(const std::string &str);
void	printSpecial(const std::string &str, int type);

#endif
