// Example program
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <functional>
#include <time.h>

class Base {
public:
    virtual ~Base(){}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


template<typename T>
Base* getInstance()
{
    return new T;
}

Base* generate(void)
{
    size_t const index = rand() % 3;

    switch (index)
    {
    case 0:
        return getInstance<A>();
        break;
    case 1:
        return getInstance<B>();
        break;
    case 2:
        return getInstance<C>();
        break;

    default:
        return getInstance<Base>();
        break;
    }
}



template<typename T>
bool is_type_of(Base* instance)
{
    return dynamic_cast<T*>(instance) != NULL;
}

#define IS_TYPE(TYPE, INSTANCE_PTR) \
{\
    if (is_type_of<TYPE>(INSTANCE_PTR)){\
        std::cout<< #TYPE << '\n';\
    }\
}

void identify_from_pointer( Base * p )
{
    IS_TYPE(A, p);
    IS_TYPE(B, p);
    IS_TYPE(C, p);
}

void identify_from_reference( Base & p )
{
    identify_from_pointer(&p);
}

int main()
{
    srand(time(0));

    Base* b;
    b = generate(); 

    if (b)
    {
        identify_from_pointer(b);
        identify_from_reference(*b);
    }
}
