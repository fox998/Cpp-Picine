
#include "ZombieEvent.hpp"

void		ZombieEvent::setZombieType(std::string type)
{
	_zombietype = type;
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(this->_zombietype, name));
}
