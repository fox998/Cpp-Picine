
#include "ZombieEvent.hpp"

void		ZombieEvent::setZombieType(std::string type)
{
	_zombietype = type;
}

Zombie		*ZombieEvent::newZombie(std::string const& name) const
{
	return (new Zombie(this->_zombietype, name));
}
