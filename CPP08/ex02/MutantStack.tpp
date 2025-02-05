#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &cpy) : std::stack<T>(cpy)
{
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &cpy)
{
	if (this != &cpy)
		std::stack<T>::operator=(cpy);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

#endif
