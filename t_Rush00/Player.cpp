/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:09:30 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:09:32 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Player.hpp"

Player::~Player()
{
	
}

Player::Player(): _score(0)
{

}

Player::Player(Player const & copy): _score(0)
{
	*this = copy;
}

Player::Player(Point const & pos, Point const & spd , int health): Ship(pos, spd, health), _score(0){}

Player &		Player::operator=(Player const & p)
{
	this->_speed = p._speed;
	this->_position = p._position;
	this->_health = p._health;
	this->_score = p._score;

	return (*this);
}

void		Player::upScore()
{
	this->_score++;
}

int			Player::getScore() const
{
	return (this->_score);
}

