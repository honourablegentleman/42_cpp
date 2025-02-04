/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:50:47 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/07 13:50:49 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*weapon;
	std::string	name;
public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &weapon);
};


#endif
