/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:22:54 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 11:22:57 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	bool	gatekeeper;
public:
	ScavTrap();
	ScavTrap(ScavTrap &copy);
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap	&operator=(ScavTrap &copy);
	void	attack(std::string const &target);
	void	guardGate();

};


#endif
