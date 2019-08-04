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

Bullet &		Bullet::operator=(Bullet const & s)
{
	this->_damage = s._damage;
	this->_position = s._position;
	this->_speed = s._speed;
}

bool		Bullet::collision(Object const & o)
{
	return (false);
}

