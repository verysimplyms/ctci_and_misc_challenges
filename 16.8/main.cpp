#include <stdio.h>
#include <string.h>
#include <iostream>

void numAsName(char givenNum[20], std::string &stringToReturn) {
	char tempArray[20];
    strncpy(tempArray, givenNum, strlen(givenNum));
    int a = strlen(givenNum);
	while (a > 0) {
        stringToReturn += " ";
		stringToReturn += givenNum[strlen(givenNum) - a];

		if((a % 3) == 0) {
			stringToReturn += " Hundred";
		} else if(a == 4) {
            stringToReturn += " Thousand";
		} else if(a == 7) {
            stringToReturn += " Million";
		} else if(a == 10) {
			stringToReturn += " Billion";
		}

		for(int i = 1; i < a; i++) {
			int k = 0;
			tempArray[k] = tempArray[i];
			k++;
		}
		a--;
	}
}

int main() {
	char num[20];
	std::string returnedString;
	std::cout << "Enter a number less than 1 Trillion: ";
	std::cin >> num;
    numAsName(num, returnedString);

    std::cout << "\n\n" << returnedString << std::endl;
    return 0;
}
