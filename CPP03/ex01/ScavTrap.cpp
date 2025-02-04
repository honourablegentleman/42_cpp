/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:22:40 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/13 11:22:46 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->gatekeeper = false;
	std::cout << "ScavTrap Default has been created! [Constructor called]"
				<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << copy.name << " has been created! [Copy constructor called]"
	<< std::endl;
	this->gatekeeper = copy.gatekeeper;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->gatekeeper = false;
	std::cout << "ScavTrap " << name << " has been created! [Name constructor called]"
	<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed! "
				"[Destructor called]" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap &copy)
{
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	this->gatekeeper = copy.gatekeeper;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hitpoints == 0)
		std::cout << "ScavTrap " << this->name << " is already dead!"
				  << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ScavTrap " << this->name << " has no energy points left!"
				  << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target
					<< ", causing " << this->attack_damage << " points of damage!"
					<< std::endl;
		this->energy_points -= 1;
	}
}

void	ScavTrap::guardGate()
{
	if (!this->gatekeeper)
	{
		std::cout << "ScavTrap " << this->name
					<< " has entered Gate keeper mode!"
					<< std::endl;
		this->gatekeeper = true;
	}
	else
	{
		std::cout << "ScavTrap " << this->name
					<< " has exited Gate keeper mode!"
					<< std::endl;
		this->gatekeeper = false;
	}
}
