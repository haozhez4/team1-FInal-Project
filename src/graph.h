#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <list>
using namespace std;
class Graph{
public:
    Graph(const string & airportFile, const string & routesFile);
    vector<int> BFS(int start);
    map<int, list<pair<int, double>>> getMap();
    pair<double, double> getLocation(int id);
    double findDistance(int id1, int id2);
private:
    map<int, list<pair<int, double>>> graph; //match id with a list of the pairs of destinations and distance
    map<int, pair<double, double>> airport; //match id with a pair of latitude and longitude
    vector<int> index; //the index matched with id
};