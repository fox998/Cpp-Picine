/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:46:21 by afokin            #+#    #+#             */
/*   Updated: 2018/06/20 15:46:23 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
class Fixed
{
	private:
		int						_fpval;
		static const int		_numOfFractBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();

		Fixed		&operator=(Fixed const &copy);

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const; 
};

std::ostream &		operator<<(std::ostream & o, Fixed const & fp);

#endif
