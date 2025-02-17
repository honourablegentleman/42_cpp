/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:09:29 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 14:09:50 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <limits>

class BitcoinExchange
{
private:
	std::map<std::string, float>	data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange	&operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();
	void	execute(char **argv);
	int		checkFormat(std::string &line);
	int		checkDate(std::string &date);
	class	CouldNotOpenFile : public std::exception {
	public:
		const char	*what() const throw();
	};
	class	InvalidFormat : public std::exception {
	public:
		const char	*what() const throw();
	};
};

#endif
