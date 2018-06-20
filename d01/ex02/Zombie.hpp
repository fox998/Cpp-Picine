
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie
{
	private:
		std::string		_type;
		std::string		_name;

	public:
		void		announce();
		Zombie(std::string type, std::string name);
};

#endif