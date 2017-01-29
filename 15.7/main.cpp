#include <stdio.h>
#include <iostream>
#include <string.h>
#include <thread>


void fizz(int x) {

    for (int i = 0; i <= x; i++) {
         if(x % 3 == 0 && x % 5 != 0) {
            std::cout << "Fizz ";
        }
    }
}

void buzz(int x) {
    for (int i = 0; i <= x; i++) {
        if(i % 5 == 0 && i % 3 != 0) {
           std::cout << "Buzz ";
        }
    }
}

void notFizzBuzz(int x) {
        for(int i = 0; i <= x; i++) {
            if((i % 5 != 0) && (i % 3 != 0)) {
            std::cout << i << " ";
        }
    }
}

void fizzBuzz(int x) {
    for(int i = 0; i <= x; i++) {
            if((i % 5 == 0) && (i % 3 == 0)) {
            std::cout << "FizzBuzz";
        }
    }
}


int main() {
 std::thread t1(fizz, 100);
 std::thread t2(buzz, 100);
 std::thread t3(notFizzBuzz, 100);
 std::thread t4(fizzBuzz, 100);

 t1.join();
 t2.join();
 t3.join();
 t4.join();
return 0;
}
