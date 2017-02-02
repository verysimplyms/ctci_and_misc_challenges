#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>

//doesnt work

int main() {
	int buffer;
	std::string givenString;
	std::vector<std::string> brokenStrings;

    std::cout << "Enter a string: " << std::endl;
    getline(std::cin, givenString);

    std::cout << "Enter a buffer size: ";
	std::cin >> buffer;


	std::stringstream ss(givenString);

	while(std::getline(ss, givenString, ' ')) {
		brokenStrings.push_back(ss.str());
		ss.clear();
	};


    std::cout << brokenStrings[0] << " ";

   // for(int i = 0; i < brokenStrings.size(); i++) {
   //     std::cout << brokenStrings[i] << " ";
   //}
}
