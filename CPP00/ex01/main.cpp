/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:04:02 by jhoddy            #+#    #+#             */
/*   Updated: 2024/10/31 13:04:03 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	print_index(Contact *contact)
{
	std::string	sep;

	sep = "--------------------------------------------------------";
	std::cout << sep << std::endl;
	std::cout << "|first name| last name|  nickname|    number|    secret|" << '\n';
	std::cout << sep << std::endl;
	contact->print_contact(contact);
	std::cout << sep << std::endl;
}

void	print_all_contacts(Phonebook *phonebook)
{
	Contact		*contact;
	std::string	sep;

	sep = "---------------------------------------------";
	std::cout << sep << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << sep << std::endl;
	for (int i = 0; i < phonebook->get_max_index(); i++)
	{
		contact = phonebook->get_contacts(i);
		std::cout << "|         " << contact->get_index() << "|";
		print_value(contact->get_f_name());
		print_value(contact->get_l_name());
		print_value(contact->get_nickname());
		std::cout << "\n" << sep << std::endl;
	}
}

void	search_command(Phonebook *phonebook)
{
	int 	i;
	int 	index;
	Contact	*contact;

	print_all_contacts(phonebook);
	std::cout << "Enter index of the contact you want to see: ";
	std::cin >> index;
	while (std::cin.fail() || index < 1 || index > 8)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index. Please enter a number between 1 and 8: ";
		std::cin >> index;
	}
	if (index > phonebook->get_max_index())
	{
		std::cout << "No contact at this index" << std::endl;
		return ;
	}
	i = index - 1;
	contact = phonebook->get_contacts(i);
	print_index(contact);
}

bool	valid_number(std::string number)
{
	int	i;

	i = 0;
	if (number[i] == '+')
		i++;
	while (number[i])
	{
		if (!isdigit(number[i]))
			return (false);
		i++;
	}
	return (true);
}

std::string	get_info(std::string prompt, bool num)
{
	std::string	info;

	std::cout << prompt;
	std::getline(std::cin >> std::ws, info);
	while (num && !valid_number(info))
	{
		std::cout << "Invalid phone number. Please enter a valid phone number: ";
		std::getline(std::cin >> std::ws, info);
	}
	return (info);
}

void	add_command(Phonebook &phonebook)
{
	Contact	contact;

	std::cout << "Enter contact information:" << std::endl;
	contact.set_f_name(get_info("Enter first name: ", false));
	contact.set_l_name(get_info("Enter last name: ", false));
	contact.set_nickname(get_info("Enter nickname: ", false));
	contact.set_number(get_info("Enter phone number: ", true));
	contact.set_darkest_secret(get_info("Enter darkest secret: ", false));
	phonebook.add_contact(contact);
}

int	main(void)
{
	Phonebook	phonebook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (command == "ADD")
			add_command(phonebook);
		else if (command == "SEARCH")
			search_command(&phonebook);
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
