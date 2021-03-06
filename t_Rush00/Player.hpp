/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:09:24 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:09:25 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PLAYER_HPP
# define	PLAYER_HPP

#include	"Ship.hpp"

class	Player : public Ship
{
	private:
		int		_score;

		Player();
	public:
		virtual ~Player();

		void	upScore();
		int		getScore() const;
		Player(Player const & copy);
		Player(Point const & position, Point const & speed, int health);

		Player &		operator=(Player const & p);
};

#endif
