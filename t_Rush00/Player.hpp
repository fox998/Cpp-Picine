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

	public:
		virtual ~Player();
		Player();
		Player(Player const & copy);

		Player &		operator=(Player const & p);
};

#endif
