#ifndef SETUP_H
#define SETUP_H
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
    bool blocked = false;
};

struct vertex{
    int ID = -1;
    vertex *parent; // Not used for this project
    string name;
    int district;
    bool visited =false;
    int distance;
    vector<adjVertex> adj;
};


class Setup
{
    public:
        Setup();
        ~Setup();
        void buildGraph(char *filename); // Builds the graph for the game
        void addEdge(string v1, string v2,int weight); // Used in building the graph
        void addVertex(string name); // Used in building the graph
        void displayEdges(); // For testing
        void shortestPath(); // For testing
        int generateEvent(string cityName); // Randomly chooses an event that may block the path
        void generateChallenge(); // Randomly decides two cities
        void assignDistricts(); // For testing
        void BFS(vertex start, vertex end); // Finds the shortest/available path to travel
        void displayCurrent(); // Prints current city
        void displayVisited(); // Prints path traveled
        void displayDistance(); // Prints distance traveled
        void displayAdjacent(string name); // Prints cities available to travel to from an input
        void newCity(string name); // Allows the user to move to a new city
        void displayEnd(); // Prints out the ending city

    protected:
    private:
        vector<vertex> vertices; // Array of cities as vertex
        vertex startingCity; // Stores start city
        vertex endingCity; // Stores end city
        vertex current; // Stores current city
        queue<string>visited; // Stores path
        int distTraveled = 0;
        int possibleDistance = 0;
        bool first = true;
};

#endif // SETUP_H
