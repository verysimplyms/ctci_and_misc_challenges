#include <iostream>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

static const int MAX_ATTEMPTS = 500;

class Jug {
    public:
        //Sets the maximum amount of water a jug can hold
        void setJugMax(int val) {
            this->jugMax = val;
        };

        //Determines whether or the jug is even
        bool isJugEven() {
            return (this->jugMax % 2 == 0) ? true : false;
        };

        //Sets the current amount of water in a jug
        void setJugCurrent(int val) {
            if(val <= this->jugMax) {
                if(val >= 0) {
                    this->jugCurrent = val;
                } else {
                    this->jugCurrent = 0;
                }

            } else {
                this->jugCurrent = this->jugMax;
            }
        };

        //returns the amount of water in a jug
        int getJugCurrent() {
            return this->jugCurrent;
        };

        //returns the maximum amount of water a jug can hold
        int getJugMax() {
            return this->jugMax;
        };

    private:
        //current amount of water in a jug
        int jugCurrent = 0;
        //maximum a jug can hold
        int jugMax;
};

int main() {
    //Uses STD namespace
    using namespace std;

    //Creates our jugs
    Jug jugA;
    Jug jugB;

    //creates the max our jug can hold
    int jugMax;

    //Creates our goal
    int goal;

    //initializes how many attempts we've done
    int attempts = 0;

    //character for determining if the user wants to continue
    char cont;

    //Prompts user to enter maximum the first jug can hold
    cout << "Enter First Jug max: ";
    cin >> jugMax;
    jugA.setJugMax(jugMax);

    //Prompts user to enter maximum the second jug can hold
    cout << "\nEnter Second Jug max: ";
    cin >> jugMax;
    jugB.setJugMax(jugMax);

    //Prompts user to enter goal
    cout << "\nEnter goal: ";
    cin >> goal;

    //Set A to the lower jug
    if(jugB.getJugMax() < jugA.getJugMax()) {
        Jug temp;
        temp = jugA;
        jugA = jugB;
        jugB = temp;
    }

    //If the goal is larger than the sum of both jugs
    if(jugA.getJugMax() + jugB.getJugMax() < goal) {
        cout << "Both jugs are too small to reach goal!" << endl;
        return 0;
    }

    //if one or both of the jugs is/are odd OR   if both jugs are even and the end goal is even
    if((!jugA.isJugEven() || !jugB.isJugEven()) || goal % 2 == 0) {

        while((jugA.getJugCurrent() + jugB.getJugCurrent()) != goal) {
            if(jugA.getJugCurrent() <= 0) {
                jugA.setJugCurrent(jugA.getJugMax());
            }

            cout << "Currently at: " << jugA.getJugCurrent() + jugB.getJugCurrent() << endl;
            cout << "Jug A: " << jugA.getJugCurrent() << "\n\nJug B: " << jugB.getJugCurrent() << "\n\n" << endl;

            if((jugA.getJugCurrent() + jugB.getJugCurrent()) == goal) {
                break;
            }

            if(jugB.getJugCurrent() == jugB.getJugMax()) {
                jugB.setJugCurrent(0);
            }

            while( jugA.getJugCurrent() > 0 && jugB.getJugCurrent() < jugB.getJugMax()) {
                jugA.setJugCurrent(jugA.getJugCurrent() - 1);
                jugB.setJugCurrent(jugB.getJugCurrent() + 1);
            }

            cout << "Currently at: " << jugA.getJugCurrent() + jugB.getJugCurrent() << endl;
            cout << "Jug A: " << jugA.getJugCurrent() << "\n\nJug B: " << jugB.getJugCurrent() << "\n\n" << endl;

            attempts++;

            if(attempts > MAX_ATTEMPTS) {
                while(attempts > 0) {
                    cout << "Max attempts reached. Continue? (Y/N): ";
                    cin >> cont;

                    if(cont == 'y' || cont == 'Y') {
                        attempts = 0;
                    } else if(cont == 'n' || cont == 'N') {
                        return 0;
                    }
                }
            }
        }
        if(attempts < MAX_ATTEMPTS) {
            cout << "Goal met: " << (jugA.getJugCurrent() + jugB.getJugCurrent()) << endl;
        }
    } else {
        //both jugs are even but end goal is odd
        cout << "Both jugs are even, but the goal is odd!" << endl;

    }

    return 0;
}
