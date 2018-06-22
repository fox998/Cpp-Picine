
#ifndef		SORCERER_HPP
# define	SORCERER_HPP

#include	<string>
#include	<iostream>
#include	"Victim.hpp"

class	Sorcerer
{
	private:
		std::string		_name;
		std::string		_titel;

		Sorcerer();
		Sorcerer(Sorcerer const & copy);

	public:
		~Sorcerer();
		Sorcerer(std::string const & name, std::string const & titel);

		Sorcerer &				operator=(Sorcerer const & s);
		
		void					polymorph(Victim const & v);
		std::string const &		getName();
		std::string const &		getTitel();

};

std::ostream &		operator<<(std::ostream	& o, Sorcerer & s);

#endif