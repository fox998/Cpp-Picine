
#pragma once

#include <string>

class Pony
{
private:
    std::string const m_name;

public:
    Pony(std::string const& name);
    ~Pony();

    void run() const;
};

