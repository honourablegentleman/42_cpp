/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:45:15 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 12:45:18 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(FragTrap &copy);
	FragTrap(std::string name);
	~FragTrap();
	FragTrap	&operator=(FragTrap &copy);
	void	highFivesGuys(void);
};

#endif
