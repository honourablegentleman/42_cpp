/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:47:19 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/05 12:47:21 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(25)
{
}

Span::Span(unsigned int n) : N(n)
{
}

Span::Span(const Span &cpy)
{
	this->value = cpy.value;
	this->N = cpy.N;
}

Span	&Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		this->N = cpy.N;
		this->value = cpy.value;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (this->value.size() < N)
		this->value.push_back(n);
	else
		throw std::out_of_range("Vector is full");
}

int	Span::shortestSpan()
{
	if (this->value.size() < 2)
		throw std::out_of_range("Vector is too small");

	std::vector<int>	tmp = this->value;
	std::sort(tmp.begin(), tmp.end());
	int	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return (min);
}

int	Span::longestSpan()
{
	if (this->value.size() < 2)
		throw std::out_of_range("Vector is too small");

	std::vector<int>	tmp = this->value;
	std::sort(tmp.begin(), tmp.end());
	int	max = tmp[tmp.size() - 1] - tmp[0];
	return (max);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + this->value.size() > this->N)
		throw std::out_of_range("Range exceeds vectors capacity");
	this->value.insert(this->value.end(), begin, end);
}
