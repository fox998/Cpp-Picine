/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:09:52 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:09:54 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ENEMY_HPP
# define	ENEMY_HPP


#include	"Ship.hpp"

class	Enemy : public Ship
{
	private:

	public:
		~Enemy();
		Enemy();
		Enemy(Enemy const & copy);
		Enemy(Point const & position, Point const & speed, int health);

		Enemy &				operator=(Enemy const & p);
};

#endif
