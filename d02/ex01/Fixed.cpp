/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:46:11 by afokin            #+#    #+#             */
/*   Updated: 2018/06/20 15:46:14 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<cmath>

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(void): _fpval(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpval = val << this->_numOfFractBits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpval = roundf(val * (1 << this->_numOfFractBits));
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed 		&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fpval = copy._fpval;
	return (*this);
}

int			Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fpval);
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpval = raw;
}

int			Fixed::toInt(void) const
{
	return (this->_fpval >> this->_numOfFractBits);
}

float		Fixed::toFloat(void) const
{
	return ( ((float)this->_fpval) / (1 << this->_numOfFractBits));
}

std::ostream &		operator<<(std::ostream & o, Fixed const & fp)
{
	o << fp.toFloat();
	return (o);
}
