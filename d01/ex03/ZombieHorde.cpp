#include "ZombieHorde.hpp"
#include <cstdlib>

std::string	randomName(std::string const& nameBegin = "name_")
{
	char const first = ('0' + std::rand() % 10);
	char const second = ('0' + std::rand() % 10);
	
    return std::string(nameBegin + first + second);
}

ZombieHorde::ZombieHorde(size_t n):
    m_ZombiesType(randomName("type_")),
    m_Zombies(NULL),
    m_Size(n)
{
    Zombie* const data = static_cast<Zombie*>(operator new(sizeof(Zombie) * m_Size));
    for(size_t i = 0; i < m_Size; ++i)
    {
        data[i] = Zombie(m_ZombiesType, randomName());
    }
    
    m_Zombies = data;
}

void ZombieHorde::announce() const
{
    for (size_t i = 0; m_Zombies && i < m_Size; ++i)
    {
        m_Zombies[i].announce();
    }
}

ZombieHorde::~ZombieHorde(){
    delete m_Zombies;
    m_Zombies = NULL;
    m_Size = 0;
}