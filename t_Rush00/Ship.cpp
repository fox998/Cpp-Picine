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

Ship::Ship(Point const & position, Point const & speed, int health) : Object(position, speed, health) {}

Bullet		Ship::doShot(Point const & speed)
{
	return (Bullet(this->_position, speed));
}

Ship &		Ship::operator=(Ship const & s)
{
	this->_speed = s._speed;
	this->_position = s._position;
	this->_health = s._health;

	return (*this);
}

bool		Ship::collision(Object & o)
{
	Point	p1(this->getPosition());
	Point	p2(o.getPosition());

	if ( p1 == p2)
	{
		o.setHealth(0);
		this->_health = 0;
		return (true);;
	}
	return (false);
}


