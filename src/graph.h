#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <list>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
    Graph(const string & airportFile, const string & routesFile);
    vector<int> BFS(int start, int destination);
    pair<vector<int>,double> dijkstra(int start, int destination);
    list<pair<int, double>> getMap(int id);
    pair<double, double> getLocation(int id);
    int findDistance(int id1, int id2);
    vector<int> rankAirport(vector<double> a);
    vector<vector<double>> normalize(vector<vector<int>> a);
    vector<double> pagerank(vector<vector<double>> a, vector<double> init,int time);
    vector<vector<int>> adjcentMatrix();
    size_t importance(int n,vector<int> rank);
private:
    map<int, list<pair<int, double>>> graph; //match id with a list of the pairs of destinations and distance
    map<int, pair<double, double>> airport; //match id with a pair of latitude and longitude
    map<int,int> index; //the index matched with id
    vector<vector<int>> adj;
    vector<int> idx;
};