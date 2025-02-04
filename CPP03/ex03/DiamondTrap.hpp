/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:09:50 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 14:09:51 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;
public:
	DiamondTrap();
	DiamondTrap(DiamondTrap &copy);
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap	&operator=(DiamondTrap &copy);
	void	attack(const std::string &target);
	void	whoAmI();
};

#endif
