/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:08:40 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:08:41 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Bullet.hpp"

Bullet::~Bullet(){}

Bullet::Bullet(){}

Bullet::Bullet(Bullet const & copy)
{
	*this = copy;
}

Bullet::Bullet(Point const & P)
{
	this->_position = P;
}

Bullet::Bullet(Point const & pos, Point const & speed):Object(pos, speed, 1)
{
	this->_position.setChar('-');
	this->_position += speed;
}

Bullet &		Bullet::operator=(Bullet const & s)
{
	this->_position = s._position;
	this->_speed = s._speed;

	return (*this);
}

bool		Bullet::collision(Object & o)
{
	Point	p1(this->getPosition());
	Point	p2(o.getPosition());

	if ( p1 == p2)
	{
		o.setHealth(o.getHealth() - this->_health);
		this->_health = 0;
		return (true);
	}
	return (false);
}

