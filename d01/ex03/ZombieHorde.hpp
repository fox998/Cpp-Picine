
#pragma once

#include "Zombie.hpp"
#include <string>

class ZombieHorde
{
private:
    std::string const m_ZombiesType;
    Zombie const* m_Zombies;
    size_t m_Size;

public:
    ZombieHorde(size_t n);
    ~ZombieHorde();

    void announce() const;
};