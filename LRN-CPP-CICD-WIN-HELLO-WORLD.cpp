#include "LRN-CPP-CICD-WIN-HELLO-WORLD.h"
#include <iostream>

void HelloWorld::Print() const {
    std::cout << "Hello World" << std::endl;
}

int main() {
    HelloWorld hw;
    hw.Print();
    return 0;
}