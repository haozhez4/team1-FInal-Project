#include <iostream>
#include <vector>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    cout << "" << endl;
    Graph g=Graph("../src/ airports.dat","../src/route.dat");

    while(true) {
        cout << "Choose an option, 1: Find the flight path with the fewest stopovers, 2: Find the flight path with the shortest distance between the airports" << endl;
        cout << "If you want to exit the program, please enter 0" << endl;
        string choice;
        cin >> choice;
        if (choice == "1"){
            cout << "Enter starting airport (1-14109)" << endl;
            string start;
            cin >> start;
            int startint = stoi(start);
            cout << "Enter destination airport (1-14109)" << endl;
            string end;
            cin >> end;
            int endint = stoi(end);
            vector<int> result = g.BFS(startint, endint);
            if (result.size() == 0) {
                    cout<< "There is no route contains the start and destination you choose" <<endl;
            }
            for (size_t i = 0; i < result.size(); i++) {
                if (i == 0) {
                    cout << "The IDs of airports of the route with the fewest stopovers" << endl;
                }
                cout << result[i] << endl;
                if (i >= 0 && i != result.size() - 1) {
                    cout << "||" << endl;
                    cout << "vv" << endl;
                }

            }
            break;

     }
        else if (choice == "2") {
            cout << "Enter starting airport (1-14109)" << endl;
            string start;
            cin >> start;
            int startint = stoi(start);
            cout << "Enter destination airport (1-14109)" << endl;
            string end;
            cin >> end;
            int endint = stoi(end);
            pair<vector<int>,double> result = g.dijkstra(startint, endint);
            if (result.first.size() == 0) {
                    cout<< "There is no route contains a start and destination you choose" <<endl;
                } else {
                    cout << "The IDs of airports of the shortest route you can go" << endl;
                    for (size_t i : result.first){
                    cout << i << endl;
                }
                cout << "The total distance is"<< result.second << "m" << endl;

            }
            break;
        } else if (choice == "0") {
            break;
        }
        else {
            cout << "Please enter a valid number (0, 1 or 2)" << endl;
        }
    }
    while(true) {
        cout << "If you want to check the popularity of the airports, please enter the ID of the airport" << endl;
        cout << "if you want to exit the program, please enter 0" << endl;
            string id;
            cin >> id;
            int idtonumber = stoi(id);
            if (idtonumber == 0) {
                return 0;
            }
            vector<vector<int>> adj = g.adjcentMatrix();
            vector<vector<double>> n = g.normalize(adj);
            vector<double> init(adj.size());
            for(size_t i = 0;i < adj.size();i++){
                init[i] = 1.0/(double)adj.size();
            }
            vector<double> people = g.pagerank(n, init, 10);
            vector<int> rank = g.rankAirport(people);
            size_t airportrank = g.importance(idtonumber,rank);
            if(airportrank == (size_t)-1){
                cout << "The airport cannot be found" << endl;
            } else {
                cout <<"the airport is " << airportrank <<"th most popular airport"<< endl;
            }
            cout << "Do you want to continue? Y/N" << endl;
            string cont;
            cin >> cont;
            if (cont != "Y" && cont != "y") {
                return 0;
            }
    
    }
    return 0;
    }