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
	std::ifstream	datafile("data.csv");
	if (!datafile.is_open())
		throw CouldNotOpenFile();
	std::string	line;
	std::getline(datafile, line);
	if (line != "date,exchange_rate")
		throw InvalidFormat();
	std::string	date;
	std::string	exch_rate;
	while (std::getline(datafile, line))
	{
		std::istringstream	ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, exch_rate);
		float	rate = std::atof(exch_rate.c_str());
		this->data[date] = rate;
	}
	datafile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	*this = cpy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	this->data = cpy.data;
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
	std::string	line;
	std::getline(in, line);
	if (line != "date | value")
		throw InvalidFormat();
	std::string			date;
	std::string			value;
	while (std::getline(in, line))
	{
		if (checkFormat(line))
			continue ;
		std::istringstream	ss(line);
		std::getline(ss, date, '|');
		date.erase(date.length() - 1);
		std::getline(ss, value);
		float	rate = std::atof(value.c_str());
		std::map<std::string, float>::iterator	it = this->data.find(date);
		if (it != this->data.end())
			std::cout << date << " => " << rate << " = " << rate * it->second << std::endl;
		else
		{
			it = this->data.lower_bound(date);
			it--;
			std::cout << date << " => " << rate << " = " << rate * it->second << std::endl;
		}
	}
	in.close();
}

int	BitcoinExchange::checkFormat(std::string &line)
{
	std::istringstream	ss(line);
	if (line.find('|') != 11)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (1);
	}
	long	value = std::atol(line.c_str() + 12);
	if (value > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	else if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	return (0);
}

const char	*BitcoinExchange::CouldNotOpenFile::what() const throw()
{
	return "could not open file.";
}

const char	*BitcoinExchange::InvalidFormat::what() const throw()
{
	return "invalid Format.";
}
