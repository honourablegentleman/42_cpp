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
	while (std::getline(datafile, line)) {
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
	while (std::getline(in, line)) {
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
		else {
			it = this->data.lower_bound(date);
			it--;
			std::cout << date << " => " << rate << " = " << rate * it->second << std::endl;
		}
	}
	in.close();
}

int	BitcoinExchange::checkDate(std::string &date)
{
	if (date.empty() || date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (1);

	for (int i = 0; i < 9; i++) {
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(date[i]))
			return (1);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
		return (1);

	int	daysinmonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysinmonth[2] = 29;

	if (day > daysinmonth[month])
		return (1);
	return (0);
}

int	BitcoinExchange::checkValue(std::string &value)
{
	if (value.empty() || (value[0] != '-' && value[0] != '+' && !std::isdigit(value[0])))
		return (1);

	size_t	i = 0;
	if (value[0] == '-' || value[0] == '+')
		i = 1;

	bool	dot = false;
	while (value[i] != '\t' && value[i] != ' ' && i < value.size()) {
		if (value[i] == '.') {
			if (dot)
				return (1);
			dot = true;
		}
		else if (!std::isdigit(value[i]))
			return (1);
		i++;
	}
	while (i < value.size()) {
		if (value[i] != '\t' && value[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	BitcoinExchange::checkFormat(std::string &line)
{
	size_t		sep_pos = line.find(" | ");
	if (sep_pos == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (1);
	}

	std::string	date = line.substr(0, sep_pos);
	if (checkDate(date)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (1);
	}

	std::string	value = line.substr(sep_pos + 3);
	if (checkValue(value)) {
		std::cerr << "Error: bad input => " << line <<  std::endl;
		return (1);
	}

	long	rate = std::atol(value.c_str());
	if (rate > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	else if (rate < 0) {
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
