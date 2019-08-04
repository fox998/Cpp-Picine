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

Object::Object(){}

Object::Object(Object const & copy)
{
	*this = copy;
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
	this->_position += p;
}

Point &				Object::move()
{
	
}
