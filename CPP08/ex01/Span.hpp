/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:55 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 12:47:11 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
	std::vector<int>	value;
	unsigned int		N;
public:
	Span();
	Span(unsigned int n);
	Span(const Span &cpy);
	Span	&operator=(const Span &cpy);
	~Span();
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};


#endif
