/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:43:52 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/07 13:43:55 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string	type;
public:
	Weapon();
	Weapon(std::string type);
	const std::string	getType(void);
	void				setType(std::string type);
};


#endif
