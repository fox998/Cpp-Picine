
#include "Human.hpp"

Human::Human()
: m_identifier(GetIdentifier(this))
{}

Brain const& Human::getBrain() const {
    return m_brain;
}

std::string const& Human::identify() const {
    return m_identifier;
}

