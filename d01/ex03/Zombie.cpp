
#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce() const
{
	std::cout << "<" << this->m_name << " (" << this->m_type << ")>";
	std::cout << " Braiiiiiiinnnssss..." << std::endl;
}

Zombie::Zombie(std::string const& type, std::string const& name)
	: m_type(type)
	, m_name(name)
{
}

void Zombie::SetName(std::string const& name)
{
	m_name = name;
}
void Zombie::SetType(std::string const& type)
{
	m_type = type;
}