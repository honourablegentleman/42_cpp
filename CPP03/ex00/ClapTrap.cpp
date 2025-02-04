/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:23:43 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/11 15:23:48 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitpoints(10), energy_points(10),
						attack_damage(0)
{
	std::cout << "ClapTrap Default has been created! [Constructor called]" <<
	std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout << "ClapTrap " << copy.name << " has been created! [Copy constructor called]"
	<< std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10),
										energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " has been created! [Name constructor called]"
	<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed! [Destructor called]"
				<< std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap &copy)
{
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hitpoints == 0)
		std::cout << "ClapTrap " << this->name << " is already dead!"
					<< std::endl;
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left!"
					<< std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", "
																		   "causing "
				  << this->attack_damage << " points of damage!"
				  << std::endl;
		this->energy_points -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitpoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!"
				  << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " has taken " << amount
				<< " damage!" << std::endl;
	if (amount >= this->hitpoints)
	{
		std::cout << "ClapTrap " << this->name << " has been destroyed!"
					<< std::endl;
		this->hitpoints = 0;
	}
	else
		this->hitpoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left!"
					<< std::endl;
	else if (this->hitpoints == 10)
		std::cout << "ClapTrap " << this->name << " has full hit points!"
					<< std::endl;
	else if (this->hitpoints + amount > 10)
	{
		std::cout << "ClapTrap " << this->name << " has repaired itself for "
				  << 10 - this->hitpoints << " hit points!" << std::endl;
		this->hitpoints = 10;
		this->energy_points -= 1;
	}
	else if (this->hitpoints == 0)
		std::cout << "ClapTrap " << this->name << " is already dead!"
					<< std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " has repaired itself for "
				  << amount << " hit points!" << std::endl;
		this->hitpoints += amount;
		this->energy_points -= 1;
	}
}
