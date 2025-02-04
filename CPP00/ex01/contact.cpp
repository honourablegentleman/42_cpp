/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:08:47 by jhoddy            #+#    #+#             */
/*   Updated: 2024/10/17 16:08:50 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::set_index(int i)
{
	index = i;
}

void	Contact::set_f_name(std::string first)
{
	f_name = first;
}

void	Contact::set_l_name(std::string last)
{
	l_name = last;
}

void	Contact::set_nickname(std::string nick)
{
	nickname = nick;
}

void	Contact::set_number(std::string num)
{
	number = num;
}

void	Contact::set_darkest_secret(std::string secret)
{
	darkest_secret = secret;
}

int	Contact::get_index()
{
	return (index);
}

std::string	Contact::get_f_name()
{
	return (f_name);
}

std::string	Contact::get_l_name()
{
	return (l_name);
}

std::string	Contact::get_nickname()
{
	return (nickname);
}

std::string	Contact::get_number()
{
	return (number);
}

std::string	Contact::get_darkest_secret()
{
	return (darkest_secret);
}

void	print_value(std::string value)
{
	if (value.length() > 10)
		std::cout << value.substr(0, 9) << ".|";
	else
	{
		for (size_t i = 0; i < 10 - value.length(); i++)
			std::cout << " ";
		std::cout << value;
		std::cout << "|";
	}
}

void Contact::print_contact(Contact *c)
{
	std::cout << "|";
	print_value(c->get_f_name());
	print_value(c->get_l_name());
	print_value(c->get_nickname());
	print_value(c->get_number());
	print_value(c->get_darkest_secret());
	std::cout << std::endl;
}
