/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:05:25 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 14:05:38 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
private:
	T				*array;
	unsigned int	the_size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);
	~Array();
	Array	&operator=(Array const &other);
	T	&operator[](unsigned int index);
	unsigned int	size() const;
};

#endif
