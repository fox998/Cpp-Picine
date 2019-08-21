/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:54:58 by afokin            #+#    #+#             */
/*   Updated: 2018/06/21 19:55:00 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ScavTrap.hpp"
#include	<iostream>

void		ScavTrap::_outputNameOfClass()
{
	std::cout << "ScavTrap : ";
}

ScavTrap::~ScavTrap()
{
	this->_outputNameOfClass();
	std::cout << "Destructor called" << std::endl;
}

ScavTrap::ScavTrap():	_name("-"),
						_hitPoints(100),
						_maxHitPoints(100),
						_energyPoints(50),
						_maxEnergyPoints(50),
						_level(1),
						_meleeAttackDamege(20),
						_rangedAttackDamege(15),
						_armorDamageReduction(3)
{
	this->_outputNameOfClass();
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name):	_name(name),
												_hitPoints(100),
												_maxHitPoints(100),
												_energyPoints(50),
												_maxEnergyPoints(50),
												_level(1),
												_meleeAttackDamege(20),
												_rangedAttackDamege(15),
												_armorDamageReduction(3)
{
	this->_outputNameOfClass();
	std::cout << "Name set constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy)
{
	this->_outputNameOfClass();
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &			ScavTrap::operator=(ScavTrap const & ft)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name  = ft._name ;
	this->_hitPoints = ft._hitPoints;
	this->_maxHitPoints = ft._maxHitPoints;
	this->_energyPoints = ft._energyPoints;
	this->_maxEnergyPoints = ft._maxEnergyPoints;
	this->_level = ft._level;
	this->_meleeAttackDamege = ft._meleeAttackDamege;
	this->_rangedAttackDamege = ft._rangedAttackDamege;
	this->_armorDamageReduction = ft._armorDamageReduction;

	return (*this);
}

void				ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name;
	std::cout << " attacks " << target;
	std::cout << " range, causing " << this->_rangedAttackDamege;
	std::cout << " points of damage !" << std::endl;
}

void				ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name;
	std::cout << " attacks " << target;
	std::cout << " melee, causing " << this->_rangedAttackDamege;
	std::cout << " points of damage !" << std::endl;
}

void				ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name;
	std::cout << " : My robotic flesh get" << amount;
	this->_hitPoints = std::max(this->_hitPoints - (int)amount, 0);
	std::cout << " points of demage! AAHH! My health : " << this->_hitPoints << std::endl;
}

void				ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name;
	std::cout << " : I found " << amount << " hit points! ";
	this->_hitPoints = std::min(this->_hitPoints + (int)amount, this->_maxHitPoints);
	std::cout << "My health : " << this->_hitPoints << std::endl;
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	int i;
	std::string		str[] = 
	{
		"So, it's a draw, eh?",
		"Until we meet again on the battlefield, friendo!",
		"What? No way, I totally had you!",
		"Wow, who say that coming?",
		"Yay! We both win!"
	};

	std::cout << this->_name;
	std::cout << " attacks " << target << " by challengeNewcomer :";
	if (this->_energyPoints >= 25)
	{
		this->_energyPoints -= 25;
		i = rand() % 5;
		std::cout << str[i] << std::endl;
	}
	else
		std::cout << "Low Energy...." << std::endl;
}
