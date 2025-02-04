/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:33:10 by jhoddy            #+#    #+#             */
/*   Updated: 2025/02/03 11:33:29 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.h"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator=(const Serializer &src);
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
};

#endif
