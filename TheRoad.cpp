#include <iostream>
#include <vector>
#include "Setup.h"
using namespace std;

int main() {
    Setup newGame;
    newGame.buildGraph("cities.txt");
    newGame.assignDistricts();
    //newGame.displayEdges();
    newGame.generateChallenge();
    cout << "Available path: " << endl;
    newGame.shortestPath();
    cout << endl;

    int choice = 0;
    while (choice != 8) {
        cout << "1. Print current city" << endl;
        cout << "2. Print ending city" << endl;
        cout << "3. Display visited cities" << endl;
        cout << "4. Print distance traveled" << endl;
        cout << "5. Find adjacent cities" << endl;
        cout << "6. Show available path to ending city" << endl;
        cout << "7. Travel to another city" << endl;
        cout << "8. End game" << endl;
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            newGame.displayCurrent();
        }
        else if (choice == 2) {
            newGame.displayEnd();
        }
        else if (choice == 3) {
            newGame.displayVisited();
        }
        else if (choice == 4) {
            newGame.displayDistance();
        }
        else if (choice == 5) {
            string name;
            cout << "Enter the city you would like adjacent cities to:" << endl;
            cin.ignore();
            getline(cin,name);
            cout << endl;
            newGame.displayAdjacent(name);
        }
        else if (choice == 6) {
            newGame.shortestPath();
        }
        else if (choice == 7) {
            string name;
            cout << "Enter the city you would like to travel to:" << endl;
            cin.ignore();
            getline(cin,name);
            cout << endl;
            newGame.newCity(name);
        }
        cout << endl;
    }
    cout << "Thanks for playing!" << endl;
    return 0;
    //newGame.shortestPath("hello","hello");
}
