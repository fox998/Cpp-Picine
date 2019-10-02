#include "Brain.hpp"
#include <sstream>

std::string GetIdentifier(void* ptr)
{
    std::stringstream stream;
    stream << ptr;
    return stream.str();
}

Brain::Brain()
    : m_identifier(GetIdentifier(this))
{
}

std::string const& Brain::identify() const
{
    return m_identifier;
}
