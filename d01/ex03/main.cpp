
#include "ZombieHorde.hpp"

#include <ctime>
#include <cstdlib>


int		main()
{
	srand(time(0));
	ZombieHorde const horde(10);
	
	ZombieHorde horde2(5);
	horde.announce();
}