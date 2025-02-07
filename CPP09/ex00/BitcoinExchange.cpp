/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:10:00 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 14:10:03 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	*this = cpy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	(void)cpy;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::execute(char **argv)
{
	std::ifstream	in(argv[1]);
	if (!in.is_open())
		throw CouldNotOpenFile();
	std::ifstream	data("data.csv");
	if (!data.is_open())
	{
		in.close();
		throw CouldNotOpenFile();
	}
	in.close();
	data.close();
}

const char	*BitcoinExchange::CouldNotOpenFile::what() const throw()
{
	return "could not open file.";
}
