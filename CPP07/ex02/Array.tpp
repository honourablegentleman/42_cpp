#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->array = NULL;
	this->the_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->the_size = n;
}

template <typename T>
Array<T>::Array(Array const &other)
{
	this->the_size = other.the_size;
	this->array = new T[other.the_size];
	for (unsigned int i = 0; i < other.the_size; i++)
		this->array[i] = other.array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	if (this == &other)
		return (*this);
	delete[] this->array;
	this->the_size = other.the_size;
	if (other.array)
	{
		this->array = new T[other.the_size];
		for (unsigned int i = 0; i < other.the_size; i++)
			this->array[i] = other.array[i];
	}
	else
		this->array = NULL;
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->the_size)
		throw std::out_of_range("Index out of range");
	return (this->array[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->the_size);
}

#endif
