/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:37:27 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:37:29 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Point.hpp"

Point::~Point(){}

Point::Point(){}

Point::Point(Point const & copy)
{
	*this = copy;
}

Point::Point(int x, int y, char c)
{
	this->_x = x;
	this->_y = y;
	this->_c = c;
}

Point &			Point::operator=(Point const & p)
{
	this->_x = p._x;
	this->_y = p._y;
	this->_c = p._c;

	return (*this);
}

Point &			Point::operator+=(Point const & p)
{
	this->_x += p._x;
	this->_y += p._y;
	this->_c += p._c;

	return (*this);
}

int				Point::getX() const
{
	return (this->_x);
}

int				Point::getY() const
{
	return (this->_y);
}

char			Point::getChar() const
{
	return (this->_c);
}

void			Point::setX(int x)
{
	this->_x = x;
}
void			Point::setY(int y)
{
	this->_y = y;
}
void			Point::setChar(char c)
{
	this->_c = c;
}
