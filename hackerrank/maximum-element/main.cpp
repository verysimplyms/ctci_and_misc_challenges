#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numberOfCommands;
    int command;
    int value;
    int i = 0;
    int j = 0;
    vector<int> stack;
    
    cin >> numberOfCommands;
    
    while(i < numberOfCommands) {
        scanf("%i", &command);
        if(command == 1) {
            scanf("%i", &value);
            stack.push_back(value);
        }
        
        if(command == 2) {
            stack.pop_back();
        }
        
        if(command == 3) {
            j = stack[0];
            for(int k = 0; k < stack.size(); k++) {
                if(stack[k] > j) {
                    j = stack[k];
                }
            }
            cout << j << endl;
        }
        
        i++;
    }
    
    return 0;
}