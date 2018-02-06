#include <stdio.h>
#include <iostream>
#include <string.h>

void compareStrings(char (string1)[10], char (string2)[10] ) {
    int j = 0;
    for(int i = 0; i < 10; i++) {
        if(string1[i] != string2[i]) {
            j++;
        }

        if(j >= 2) {
            std::cout << "string1 and string2: False" << std::endl;
            break;
        }
    }

    if(j < 2 ) {
        std::cout << "string1 and string2: True" << std::endl;
    }
}

int main() {

    char test[10] = "not new!!";
    char testTwo[10] = "not new! ";
    char testPerm[10] = "new!!not ";
    int charTestCount[257] = {0};
    int charTestTwoCount[257] = {0};
    int charTestPermCount[257] = {0};

    compareStrings(test, testTwo);
    compareStrings(test, testPerm);

}
