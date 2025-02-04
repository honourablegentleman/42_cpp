/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:23:55 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 15:23:59 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	hitpoints;
	unsigned int	energy_points;
	unsigned int	attack_damage;
public:
	ClapTrap();
	ClapTrap(ClapTrap &copy);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap	&operator=(ClapTrap &copy);
	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif //CPP03_CLAPTRAP_HPP
