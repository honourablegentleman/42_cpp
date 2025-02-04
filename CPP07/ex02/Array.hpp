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
	Array() {
		this->array = NULL;
		this->the_size = 0;
	};
	Array(unsigned int n) {
		this->array = new T[n];
		this->the_size = n;
	};
	Array(Array const &other) {
		this->the_size = other.the_size;
		this->array = new T[other.the_size];
		for (unsigned int i = 0; i < other.the_size; i++)
			this->array[i] = other.array[i];
	};
	~Array() {
		delete[] this->array;
	};
	Array	&operator=(Array const &other) {
		if (this == &other)
			return *this;
		delete[] array;
		this->the_size = other.the_size;
		this->array = new T[other.the_size];
		for (unsigned int i = 0; i < other.the_size; i++)
			this->array[i] = other.array[i];
		return *this;
	};
	int	&operator[](unsigned int index) {
		if (index >= this->the_size)
			throw std::out_of_range("Index out of range");
		return this->array[index];
	};
	unsigned int	size() const {
		return this->the_size;
	};
};

#endif
