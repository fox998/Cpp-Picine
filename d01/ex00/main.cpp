#include "Pony.hpp"

#include <iostream>

void ponyOnTheHeap(char const *name) {
	Pony const * const pony = new Pony(name);
    pony->run();
    pony->~Pony();
    pony->run();
    pony->~Pony();
}

void ponyOnTheStack(char const *name) {
	Pony const pony(name);
    pony.run();
    pony.~Pony();
    pony.run();
}

int main()
{
    std::cout << "ponyOnTheHeap start\n";
    ponyOnTheHeap("Heap");
    std::cout << "ponyOnTheHeap end\n";

    std::cout << "ponyOnTheStack start\n";
    ponyOnTheStack("Stack");
    std::cout << "ponyOnTheStack end\n";
}