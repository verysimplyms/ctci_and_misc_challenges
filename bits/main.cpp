#include <string.h>
#include <stdlib.h>
#include <bitset>
#include <stdio.h>
#include <iostream>

int main() {
    std::bitset<4> test1;
    std::bitset<4> test2;

    test2[1] = 1;
    test2[0] = 1;

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;

    std::cout << "\n\n" << std::endl;

    std::cout << (test1 ^ test2) << std::endl;
    std::cout << (test2 & test1) << std::endl;

    test1[0] = 1;

    std::cout << "\n\n" << std::endl;

    std::cout << (test1 ^ test2) << std::endl;
    std::cout << (test2 & test1) << std::endl;

    test1 = {0};
    test2 = {0};

    std::cout << "\n\n" << std::endl;

    std::cout << (test1 ^ test2) << std::endl;
    std::cout << (test2 & test1) << std::endl;


    test1[0] = 1;
    test2[1] = 1;

    std::cout << "\n\n" << std::endl;

    std::cout << (test1 ^ test2) << std::endl;

    return 0;
}
