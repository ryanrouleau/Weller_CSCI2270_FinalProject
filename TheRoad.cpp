#include <iostream>
#include <vector>
#include "Setup.h"
using namespace std;

int main() {
    cout << "You have opened 'The Road'." << endl;
    cout << endl << "The rules are easy: You start at one city and must reach another." << endl;
    cout << "But, some roads are blocked and there is a chance your path may be obstructed." << endl;
    cout << "Also, the 'available path' provided is not necessary the fastest." << endl;
    cout << "All you need to do is strategically use the menu to navigate to the final city." << endl;
    cout << "Simple, right...?" << endl << endl;

    Setup newGame; // Initialize a new sequence of the game
    newGame.buildGraph("cities.txt"); // Builds the graph of cities
    newGame.assignDistricts();
    //newGame.displayEdges();
    newGame.generateChallenge(); // Generates the start and end city
    cout << "Available path: " << endl;
    newGame.shortestPath(); // Offers the user a potential path
    cout << endl;

    int choice = 0;
    while (choice != 8) { // Menu
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
            newGame.displayCurrent(); // Prints out current city
        }
        else if (choice == 2) {
            newGame.displayEnd(); // Prints out the end city if the user forgets
        }
        else if (choice == 3) {
            newGame.displayVisited(); // Prints out the cities you have gone through so far
        }
        else if (choice == 4) {
            newGame.displayDistance(); // Prints out the distance you have traveled.
        }
        else if (choice == 5) {
            string name;
            cout << "Enter the city you would like adjacent cities to:" << endl; // The user may check possible cities
            cin.ignore();
            getline(cin,name);
            cout << endl;
            newGame.displayAdjacent(name); // Displays all cities with open roads to the input city
        }
        else if (choice == 6) {
            newGame.shortestPath(); // Provides an available/potential path
        }
        else if (choice == 7) {
            string name;
            cout << "Enter the city you would like to travel to:" << endl;
            cin.ignore();
            getline(cin,name);
            cout << endl;
            newGame.newCity(name); // Allows the user to attempt to travel to a new city - may generate an issue
        }
        cout << endl;
    }
    cout << "Thanks for playing!" << endl;
    return 0;
    //newGame.shortestPath("hello","hello");
}
