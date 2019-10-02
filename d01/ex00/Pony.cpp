

#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string const& name)
    : m_name(name)
{
    std::cout << "Pony: " << m_name << " constructed \n";
}

Pony::~Pony()
{
    std::cout << "Pony: " << m_name << " destructed \n";
}

void Pony::run() const
{
    std::cout << "Pony: " << m_name << " run \n";
}
