#include <stdio.h>
#include <string.h>

int main() {
    char test[10] = "not new!!";
    int checkUnique[257] = {0};

    for(int i = 0; i < strlen(test); i++ ) {

        if(checkUnique[(int)test[i]] == 0) {
            printf("Never seen %c character before!\n", test[i]);
            checkUnique[(int)test[i]] = 1;
            printf("Count: %d\n", checkUnique[(int)test[i]]);
        } else {
            checkUnique[(int)test[i]]++;
            printf("Count: %d\n", checkUnique[(int)test[i]]);
            printf("%c is repeated! \n", test[i]);
        }

    }

}
