
#pragma once

#include <stack>


template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    typedef typename std::stack<T, Container> Super;
public:
    typedef typename Container::iterator iterator;

    MutantStack(){}
    ~MutantStack(){}
    MutantStack(MutantStack const& other) : Super(other) {}

    MutantStack& operator=(MutantStack const& other) { return Super::operator=(other); }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

