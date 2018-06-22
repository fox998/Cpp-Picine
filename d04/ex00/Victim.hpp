
#ifndef		VICTIM_HPP
# define	VICTIM_HPP

#include	<string>
#include	<iostream>

class	Victim
{
	protected:
		std::string		_name;
		
		Victim();
		Victim(Victim const & copy);

	public:
		~Victim();
		Victim(std::string const & name);

		Victim &					operator=(Victim const & v);

		virtual void				getPolymorphed() const;
		std::string const &			getName() const;
};

std::ostream &		operator<<(std::ostream & o, Victim const & v);

#endif
