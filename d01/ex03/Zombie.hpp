
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie
{
	private:
		std::string m_type;
		std::string	m_name;

	public:
		void		announce() const;
		Zombie(std::string const& type = "", std::string const& name = "");

		void SetName(std::string const& name);
		void SetType(std::string const& type);
};

#endif