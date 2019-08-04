/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:04:16 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 15:04:17 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Ship.hpp"

Ship::~Ship(){}

Ship::Ship(){}

Ship::Ship(Ship const & copy)
{
	*this = copy;
}

Bullet		Ship::doShot()
{
	return (Bullet());
}

Ship &		Ship::operator=(Ship const & s)
{
	this->_speed = s._speed;
	this->_position = s._position;
	this->_health = s._health;

	return (*this);
}

int					Ship::getHealth() const
{
	return (this->_health);
}

bool		Ship::collision(Object const & o)
{
	return (false);
}


