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
#include <exception>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange	&operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();
	void	execute(char **argv);
	class	CouldNotOpenFile : public std::exception
	{
	public:
		const char	*what() const throw();
	};
};

#endif
