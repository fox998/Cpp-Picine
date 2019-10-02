// Example program
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
//#include <cstdlib>

struct A
{
    char chars1[8];
    int integer;
    char chars2[8];
};

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void * serialize( void )
{
    void* arr = new A;

    for (size_t i = 0; i < sizeof(A); i++)
    {
        static_cast<char*>(arr)[i] = rand() % 100 + 1;
    }

    return arr;
}

Data * deserialize( void * raw )
{
    Data* data = NULL;
    if (raw)
    {
        data = new Data;
        *data = *static_cast<Data*>(raw);
    }

    return data;
}

int main()
{
    A* a = static_cast<A*>(serialize());

    std::cout << a->chars1 << "\\" << a->integer << "\\" << a->chars2 << std::endl;

    Data d;
    d.n = 42;
    d.s1 = "Hello";
    d.s2 = "World";

    Data *copy_d = deserialize(&d);

    std::cout << copy_d->s1 << "\\" << copy_d->n << "\\" << copy_d->s2 << std::endl;
}
