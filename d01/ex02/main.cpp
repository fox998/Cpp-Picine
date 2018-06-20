
#include "ZombieEvent.hpp"
#include <ctime>
#include <cstdlib>

void	randomChump()
{
	ZombieEvent		e;
	Zombie			*z;
	std::string		randname("rand_");

	srand(time(0));
	e.setZombieType("type1");
	randname += (char)('0' + std::rand() % 10);
	randname += (char)('0' + std::rand() % 10);
	z = e.newZombie(randname);
	z->announce();
	delete z;
}


int		main()
{
	Zombie z("ZombieOntheSrack", "Stack");

	z.announce();
	randomChump();
}