#pragma once
#include <string>

#include "Brain.hpp"

class Human
{
private:
    std::string const m_identifier;
    Brain const m_brain;

public:
    Human();
    Brain const& getBrain() const;
    std::string const& identify() const;
};


