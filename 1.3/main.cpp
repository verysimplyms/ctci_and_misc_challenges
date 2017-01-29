#include <iostream>
#include <string.h>
#include <stdio.h>

std::string stringReturn(char input[]) {
    int charCount = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            charCount += 3;
        } else {
            charCount++;
        }
    }

    char newArray[charCount];
    int j = 0;
    int otherArray = 0;
    while(otherArray < charCount) {
        if(input[otherArray] == ' ') {
            newArray[j] = '%';
            newArray[j+1] = '2';
            newArray[j+2] = '0';
            j += 3;
        } else {
            newArray[j] = input[otherArray];
            j++;
        }
        otherArray++;
    }

    return newArray;
}

int main() {
    char textMsg[] = "Just A Test";

    std::cout << stringReturn(textMsg) << std::endl;
}
