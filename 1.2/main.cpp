#include <stdio.h>
#include <iostream>
#include <string.h>

void charCountReturn(char (charArray)[10], int (charCount)[257]) {
    for(int i = 0; i < strlen(charArray); i++ ) {
        if(charCount[(int)charArray[i]] == 0) {
            charCount[(int)charArray[i]] = 1;
        } else {
            charCount[(int)charArray[i]]++;
        }
    }
}

bool permutationComparison(char (charArray1)[10], char (charArray2)[10], int (charCount1)[257], int (charCount2)[257]) {

    if(strlen(charArray1) != strlen(charArray2)) {
        return false;
    }

    for(int i = 0; i < strlen(charArray1); i++) {
        if(charCount1[(int)charArray1[i]] != charCount2[(int)charArray1[i]]) {
            return false;
        }

        if(charCount1[(int)charArray2[i]] != charCount2[(int)charArray2[i]]) {
            return false;
        }
    }

    return true;
}

int main() {

    char test[10] = "not new!!";
    char testPerm[10] = "new!!not ";
    int charTestCount[257] = {0};
    int charTestPermCount[257] = {0};

    charCountReturn(test, charTestCount);
    charCountReturn(testPerm, charTestPermCount);

    std::cout << "Are the strings \" " << test << " \" and \" " << testPerm << " \" permutations?: " << permutationComparison(test, testPerm, charTestCount, charTestPermCount) << std::endl;

    strcpy(test, "different");
    charCountReturn(test, charTestCount);
   // charCountReturn(testPerm, charTestPermCount);

    std::cout << "Are the strings \" " << test << " \" and \" " << testPerm << " \" permutations?: " << permutationComparison(test, testPerm, charTestCount, charTestPermCount) << std::endl;
}
