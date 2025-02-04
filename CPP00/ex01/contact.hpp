/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:59:59 by jhoddy            #+#    #+#             */
/*   Updated: 2024/10/31 13:00:01 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	int			index;
	std::string	f_name;
	std::string	l_name;
	std::string	nickname;
	std::string	number;
	std::string	darkest_secret;
public:
	Contact() : index(0), f_name(""), l_name(""), nickname(""), number(""),
				darkest_secret("") {}
	void		print_contact(Contact *c);
	void		set_index(int i);
	void		set_f_name(std::string first);
	void		set_l_name(std::string last);
	void		set_nickname(std::string nick);
	void		set_number(std::string num);
	void		set_darkest_secret(std::string secret);
	int			get_index();
	std::string	get_f_name();
	std::string	get_l_name();
	std::string	get_nickname();
	std::string	get_number();
	std::string	get_darkest_secret();
};

void	print_value(std::string value);

#endif
