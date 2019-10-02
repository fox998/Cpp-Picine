/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:07:12 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:07:14 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Object.hpp"

Object::~Object(){}

Object::Object(): f(1){}

Object::Object(Object const & copy)
{
	*this = copy;
}

Object::Object(Point const & position, Point const & speed, int health): f(1)
{
	this->_position = position;
	this->_speed = speed;
	this->_health = health;
}

Object &			Object::operator=(Object const & o)
{
	this->_position = o._position;
	this->_speed = o._speed;

	return (*this);
}

Point const &		Object::getPosition() const
{
	return (this->_position);
}

void				Object::setPosition(Point const & p)
{
	char c = this->_position.getChar();
	this->_position = p;
	this->_position.setChar(c);
}

Point const &				Object::move()
{
	this->_position += this->_speed;

	return (this->_position);
}


Point const &				Object::move(Point const & p)
{
	this->_position += p;

	return (this->_position);
}

int					Object::getHealth() const
{
	return (this->_health);
}

void				Object::setHealth(int health)
{
	this->_health = health;
}

void				Object::drow(int color)
{
	this->_position.drow(color);
}
