#pragma once
#include <string>

std::string GetIdentifier(void* ptr);

class Brain
{
private:
    std::string const m_identifier;

public:
    Brain();

    std::string const& identify() const;
};

