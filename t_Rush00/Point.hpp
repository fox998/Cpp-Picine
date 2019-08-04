/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:37:21 by afokin            #+#    #+#             */
/*   Updated: 2018/06/23 14:37:22 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		POINT_HPP
# define	POINT_HPP

class		Point
{
	private:
		int		_x;
		int		_y;
		char	_c;

	public:
		~Point();
		Point();
		Point(Point const & copy);
		Point(int x, int y, char c);

		Point &			operator=(Point const & p);
		Point &			operator+=(Point const & p);

		int				getX() const;
		int				getY() const;
		char			getChar() const;

		void			setX(int x);
		void			setY(int y);
		void			setChar(char c);
};

#endif
