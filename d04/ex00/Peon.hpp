

#ifndef		PEON_HPP
# define	PEON_HPP

#include	"Victim.hpp"

class	Peon : public Victim
{
	protected:
		Peon();
		Peon(Peon const & copy);

	public:
		~Peon();
		Peon(std::string const &name);

		Peon &				operator=(Peon const & p);

		virtual void		getPolymorphed() const;
};

std::ostream &		operator<<(std::ostream & o, Victim const & v);

#endif