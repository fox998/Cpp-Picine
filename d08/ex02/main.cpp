
#include <stack>
#include <vector>
#include <iostream>
#include <exception>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

    using std::stack<T, Container>::c;

public:
    typedef Container::iterator iterator;
    //using begin = decltype(container_type::begin);

    //using iterator = decltype(this->c.begin());


    iterator begin() { return std::begin(c); }
    iterator end() { return std::end(c); }
};


// template<typename T, typename Container = std::deque<T>>
// class iterable_stack
// : public std::stack<T, Container>
// {
//     using std::stack<T, Container>::c;

// public:

//     // expose just the iterators of the underlying container
//     auto begin() { return std::begin(c); }
//     auto end() { return std::end(c); }

//     auto begin() const { return std::begin(c); }
//     auto end() const { return std::end(c); }
// };

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}