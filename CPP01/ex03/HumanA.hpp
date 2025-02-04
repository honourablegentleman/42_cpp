/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:50:40 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/07 13:50:41 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	Weapon		&weapon;
	std::string	name;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void);
};


#endif
