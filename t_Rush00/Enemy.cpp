/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:09:57 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:09:59 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Enemy.hpp"

Enemy::~Enemy()
{

}

Enemy::Enemy()
{

}

Enemy::Enemy(Enemy const & copy)
{
	*this = copy;
}

Enemy &				Enemy::operator=(Enemy const & p)
{
	this->_speed = p._speed;
	this->_position = p._position;
	this->_health = p._health;
}

