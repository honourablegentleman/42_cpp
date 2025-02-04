/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:12:10 by jhoddy            #+#    #+#             */
/*   Updated: 2024/10/15 12:12:13 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
	int		index;
	int		max_index;
public:
	Phonebook() : index(0), max_index(0) {}
	void	add_contact(Contact& contact);
	int		get_max_index();
	Contact	*get_contacts(int index);
};

void		add_command(Phonebook &phonebook);
void		print_index(Contact *contact);
void		search_command(Phonebook *phonebook);
bool		valid_number(std::string number);
std::string	get_info(std::string prompt, bool num);
void		print_all_contacts(Phonebook *phonebook);

#endif
