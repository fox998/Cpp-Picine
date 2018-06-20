
#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce()
{
	std::cout << "<" << this->_name << " (" << this->_type << ")>";
	std::cout << " Braiiiiiiinnnssss..." << std::endl;
}

Zombie::Zombie(std::string type, std::string name): _type(type), _name(name)
{
}