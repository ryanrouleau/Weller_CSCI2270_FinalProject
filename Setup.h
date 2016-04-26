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
    vertex *parent;
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
        void buildGraph(char *filename);
        void addEdge(string v1, string v2,int weight);
        void addVertex(string name);
        void displayEdges();
        void shortestPath();
        int generateEvent(string cityName);
        void generateChallenge();
        void assignDistricts();
        void BFS(vertex start, vertex end);
        void newCity();
        void displayCurrent();
        void displayVisited();
        void displayDistance();
        void displayAdjacent(string name);
        void newCity(string name);
        void displayEnd();

    protected:
    private:
        vector<vertex> vertices;
        vertex * findVertex(string name);
        vertex startingCity;
        vertex endingCity;
        vertex current;
        queue<string>visited;
        int distTraveled = 0;
        int possibleDistance = 0;
        bool first = true;
};

#endif // SETUP_H
