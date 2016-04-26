#include "Setup.h"
#include<vector>
#include<iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include<queue>
using namespace std;

Setup::Setup()
{
    //ctor
}

Setup::~Setup()
{
    //dtor
}

void Setup::buildGraph(char *filename) {
    string cityArray[10] = {"Boston","Boulder","Chicago","Disneyland","Miami","New Orleans","New York","Portland","San Francisco","Seattle"};
    for (int i = 0; i < 10; i++) {
        addVertex(cityArray[i]);
    }
    ifstream textFile;
    string txt;
    textFile.open(filename);
    if (textFile.good()) {
        int distance;
        string name;
        int count = 1;
        int cityCount = 0;
        bool zeroPassed;
        while (true) {
            if (count != 1) {
                if (getline(textFile, txt, ','))  {
                    name = txt;
                    zeroPassed = false;
                }
                else {

                }
                while (cityCount <= 9) {
                    if (cityCount == 9) {
                        if (getline(textFile, txt)) {
                            distance = atoi(txt.c_str());
                            //cout << name << cityArray[cityCount] << distance << endl;
                            if (name == cityArray[cityCount]) {
                                zeroPassed = true;
                            }
                            if (distance != -1 && distance != 0 && zeroPassed == true) {
                                addEdge(name,cityArray[cityCount],distance);
                            }
                            cityCount++;
                        }
                    }
                    else {
                        if (getline(textFile, txt, ',')) {
                            distance = atoi(txt.c_str());
                            //cout << name << cityArray[cityCount] << distance << endl;
                            if (name == cityArray[cityCount]) {
                                zeroPassed = true;
                            }
                            if (distance != -1 && distance != 0 && zeroPassed == true) {
                                addEdge(name,cityArray[cityCount],distance);
                            }
                            cityCount++;
                        }
                    }
                }
                cityCount = 0;
            }
            else {

            }
            if (count == 11) {
                break;
            }
            count++;
        }
    }
}

void Setup::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}


void Setup::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Setup::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].ID << ":" << vertices[i].name<<" --> ";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            if (j!= vertices[i].adj.size()-1) {
            cout<<vertices[i].adj[j].v->name<<" -- ";
            }
            else {
              cout<<vertices[i].adj[j].v->name;
            }
        }
        cout<<endl<<endl;
    }
}

void Setup::assignDistricts() {
    int IDcount = 0;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].ID == -1) {
            IDcount++;
            queue<vertex*> districtQueue;
            districtQueue.push(&vertices[i]);
            while (!districtQueue.empty()) {
                vertex *temp = districtQueue.front();
                districtQueue.pop();
                temp->ID = IDcount;
                for (int j = 0; j < temp->adj.size(); j++) {
                    if (temp->adj[j].v->ID == -1 && vertices[i].adj[j].weight != -1) {
                        districtQueue.push(temp->adj[j].v);
                    }
                }
            }
        }
    }
    //displayEdges();
}

void Setup::shortestPath() {
    /*vertex start;
    vertex ender;
    bool foundS = false;
    bool foundE = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name.compare(startingCity) == 0) {
            start = vertices[i];
            foundS = true;
        }
        else if (vertices[i].name.compare(endingCity) == 0) {
            ender = vertices[i];
            foundE = true;
        }
    }*/

    if (current.ID != endingCity.ID || startingCity.ID != endingCity.ID) {
        cout << "There is no longer a safe path." << endl;
    }
    else {
        BFS(current, endingCity);
    }
}

void Setup::BFS(vertex start, vertex end) {
    start.visited = true;
    bool completed = false;
    start.distance = 0;
    int distance = 0;
    int smallest = 1500;
    queue<vertex*> endPath;
    queue<vertex*> path;
    path.push(&start);
    while (!path.empty()) {
        vertex *temp = new vertex;
        temp = path.front();
        //adjVertex temp2 = path.front()->a;
        endPath.push(temp);
        //cout << temp->name;
        path.pop();
        for (int j = 0; j < temp->adj.size(); j++) {
            if (!temp->adj[j].v->visited && temp->adj[j].v->name != start.name && !temp->adj[j].blocked) {
                    temp->adj[j].v->distance = temp->distance + 1;
                    distance++;
                    //cout << temp->adj[j].weight << endl;
                    if (first == true) {
                        possibleDistance = possibleDistance + temp->adj[j].weight;
                    }
                    temp->adj[j].v->parent = temp;
                    temp->adj[j].v->visited = true;
                    path.push(temp->adj[j].v);
                    if (temp->adj[j].v->name == end.name) {
                        //cout << temp->adj[j].v->distance;
                        while (!endPath.empty()) {
                            vertex *tmp = endPath.front();
                            cout << tmp->name << "-->";
                            endPath.pop();
                        }
                        cout << temp->adj[j].v->name;
                        completed = true;
                        cout << endl;
                        break;
                    }
            }
        }
        if (path.empty() && !completed) {
            cout << endl << "..." << endl << "Oh no! There are no more paths to the destination." << endl;
            cout << "It was a good effort, but I guess the zombies have a new snack." << endl << "Thanks for playing!" << endl;
            exit(0);
        }
        if (completed == true) {
            for (int i = 0; i < vertices.size(); i++) {
                vertices[i].visited = false;
                if (first == true) {
                    first = false;
                }
            }
            break;
        }
    }
}

void Setup::generateChallenge() {
    srand(time(NULL));
    int s = rand()%10;
    int e = s;
    while (e == s) {
        srand(time(NULL));
        e = rand()%10;
    }
    //cout << e <<" " << s << endl;
    startingCity = vertices[s];
    endingCity = vertices[e];
    startingCity.visited = true;
    current = startingCity;
    visited.push(current.name);
    //cout << startingCity.name << endl;
    //cout << endingCity.name << endl;
    cout << "The game has begun!" << endl;
    cout << "You must get from " << startingCity.name << " to " << endingCity.name << "." << endl;
    cout << "Good luck!" << endl << endl;
}

void Setup::displayCurrent() {
    cout << current.name << endl;
}

void Setup::displayEnd() {
    cout << endingCity.name << endl;
}

void Setup::displayVisited() {
    queue<string> temp = visited;
    string tmp = temp.front();
    cout << tmp;
    temp.pop();
    while (!temp.empty()) {
        tmp = temp.front();
        cout << "-->" << tmp;
        temp.pop();
    }
    cout << endl;
}

void Setup::displayDistance() {
    cout << "You have traveled " << distTraveled << " miles." << endl;
    //cout << possibleDistance << endl;
}

void Setup::displayAdjacent(string name) {
    cout << "Adjacent cities to " << name << ":" << endl;
    vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == name) {
            for (int j = 0; j < vertices[i].adj.size(); j++) {
                if (vertices[i].adj[j].weight != -1) {
                    cout << vertices[i].adj[j].v->name << " -- ";
                    cout << vertices[i].adj[j].weight<< " miles" << endl;
                }
            }
            break;
        }
    }
}

void Setup::newCity(string name) {
    bool found = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == current.name) {
            for (int j = 0; j < vertices[i].adj.size(); j++) {
                if (vertices[i].adj[j].v->name == name && vertices[i].adj[j].weight != -1) {
                    found = true;
                    break;
                }
            }
            break;
        }
    }
    if (found == false && name != current.name) {
            //cout << current.name;
        cout << "No safe path to " << name << " from " << current.name <<"." <<endl;
    }
    else if (name == current.name) {
        cout << "You're already in " << current.name << "." << endl;
    }
    else {
        int eventNo = generateEvent(name);
        if (eventNo == 0 || eventNo == 4 || eventNo == 5) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].name == name) {
                    for (int j = 0; j < current.adj.size(); j ++) {
                        if (current.adj[j].v->name == name) {
                            distTraveled = distTraveled + current.adj[j].weight;
                            break;
                        }
                    }
                    current = vertices[i];
                    break;
                }
            }
            visited.push(current.name);
            if (current.name == endingCity.name) {
                cout <<endl << endl << endl <<  "Congratulations!" << endl;
                cout << "You reached the destination." << endl;
                cout << endl << "How did you do?" << endl << endl;
                cout << "Path traveled:" << endl;
                displayVisited();
                cout << "Distanced covered: " << endl;
                cout << distTraveled << " miles" << endl;
                cout << "Distance calculated by original path:" << endl;
                cout << possibleDistance << " miles" << endl;

                if (distTraveled <= possibleDistance) {
                    cout << endl << "Good job! You traveled the shortest distance." << endl;
                }
                else {
                    cout << endl << "Looks like you took the long way around. Oh well." << endl;
                }
                cout << endl << "Thanks for playing!" << endl;
                exit(0);
            }
        }
        else {
            //cout << current.name;
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].name == current.name) {
                    for (int j = 0; j < current.adj.size(); j ++) {
                        if (current.adj[j].v->name.compare(name) == 0) {
                            //cout << vertices[i].adj[j].v->name << endl;
                            vertices[i].adj[j].weight = -1;
                            vertices[i].adj[j].blocked = true;
                            current.adj[j].weight = -1;
                            current.adj[j].blocked = true;
                            break;
                        }
                    }
                    break;
                }
            }
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].name == name) {
                    for (int j = 0; j < vertices[i].adj.size(); j ++) {
                        if (vertices[i].adj[j].v->name == current.name) {
                            //cout << vertices[i].adj[j].v->name << endl;
                            vertices[i].adj[j].weight = -1;
                            vertices[i].adj[j].blocked = true;
                            break;
                        }
                    }
                    break;
                }
            }
            for (int i = 0; i < vertices.size(); i++) {
                vertices[i].ID = -1;
            }
            assignDistricts();
            cout << endl << "Available path: " << endl;
            shortestPath();
        }
    }
}

int Setup::generateEvent(string cityName) {
    srand(time(NULL));
    int eventNo = rand()%6;
    if (eventNo == 0 || eventNo == 4 || eventNo == 5) {
        cout << "You successfully traveled to " << cityName << "." << endl;
    }
    else if (eventNo == 1) {
        cout << "Oh no! There is a huge hoard of zombies swarming the roads." << endl;
        cout << "The path to " << cityName << " from " << current.name << " has been blocked." << endl;
    }
    else if (eventNo == 2) {
        cout << "A crazy group of cannibalistic survivors threaten your passage." << endl;
        cout << "The path to " << cityName << " from " << current.name << " has been blocked." << endl;
    }
    else if (eventNo == 3) {
        cout << "Mother Nature is angry - the weather is not safe to travel in." << endl;
        cout << "The path to " << cityName << " from " << current.name << " has been blocked." << endl;
    }
    return eventNo;
}
