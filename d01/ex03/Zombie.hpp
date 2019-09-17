
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie
{
	private:
		std::string const	m_type;
		std::string const	m_name;

	public:
		void		announce() const;
		Zombie(std::string const& type, std::string const& name);
};

#endif