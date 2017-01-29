#include <stdio.h>
#include <iostream>
#include <string.h>

int main() {
    int i = 10;
    int j = 33;

    std::cout << "i: " << i << "\nj: " << j << std::endl;
    i = i + j;
    j = i - j;
    i = i - j;

    std::cout << "\n\ni: " << i << "\nj: " << j << std::endl;
}
