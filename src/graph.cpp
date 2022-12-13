#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>


Graph::Graph(const string & airportFile, const string & routesFile){
    ifstream ifs{airportFile};
    int ix = 0;
    while(ifs.good()){
        string s;
        getline(ifs, s);
        list<std::pair<int, double>> l;
        string u1;
        string u2;
        string u3;
        int start = 0;
        int end = s.find(",");
        u1= s.substr(start, end - start);
        for(int i = 0; i < 6;i++){
            start = end + 1;
            end = s.find(",", start);
        }
        u2 = s.substr(start, end - start);
        start = end + 1;
        end = s.find(",", start);
        u3 = s.substr(start, end - start);
        int id = stoi(u1);
        if(u2 == "\\N"||u3 == "\\N"){
            continue;
        }
        double la = stod(u2);
        double lo = stod(u3);
        pair<double, double> location(la,lo);
        index.insert(pair<int,int>(id,ix));
        ix++;
        idx.push_back(id);
        graph.insert(pair<int, list<pair<int, double>>>(id,l));
        airport.insert(pair<int,pair<double,double>>(id,location));
    }
    adj.resize(index.size());
    for(size_t i = 0; i < adj.size();i++){
        adj[i].resize(index.size());
        for(size_t j = 0;j<index.size();j++){
            adj[i][j] = 0;
        }
    }
    ifstream ifstr{routesFile};
    while(ifstr.good()){
        string s;
        getline(ifstr, s);
        string s1;
        string s2;
        int start = 0;
        int end = s.find(",");
        for(int i = 0; i < 3;i++){
            start = end + 1;
            end = s.find(",", start);
        }
        s1= s.substr(start, end - start);
        start = end + 1;
        end = s.find(",", start);
        start = end + 1;
        end = s.find(",", start);
        s2= s.substr(start, end - start);
        if(s1 == "\\N"||s2 == "\\N"){
            continue;
        }
        int id1 = stoi(s1);
        int id2 = stoi(s2);
        if(index.find(id1)!=index.end()&&index.find(id2)!=index.end()){
            int a = index.find(id1)->second;
            int b = index.find(id2)->second;
            adj[a][b] = 1;
        }
        double d = findDistance(id1,id2);
        if (graph.find(id1) == graph.end()){
            continue;
        }
        graph.find(id1)->second.push_back(std::pair<int, double>(id2,d));
    }
}


list<pair<int, double>> Graph::getMap(int id) {
    return graph.find(id)->second;
}

pair<double, double> Graph::getLocation(int id) {
    return airport.find(id)->second;
}



//  Performs BFS to find route from start airport to destination airport then stops search
vector<int> Graph::BFS(int start, int destination) {
    //  Mark all airports as not visited
    vector<bool> visited(14110);    //  highest airport ID #
    for (unsigned i=0; i<14110; i++) {
        visited[i] = false;
    }
    //  initialize BFS
    queue<int> airportQueue;    //  queue for BFS
    vector<int> previous(14110,-1); //  maintains previous airport visited
    previous[start] = start;    //  initialize starting airport to start
    airportQueue.push(start);   //  enqueue first airport
    int current = start;    //  current airport being visited

    //  BFS
    while (!airportQueue.empty()) {
        current = airportQueue.front();
        for (auto it=graph[current].begin(); it!=graph[current].end(); it++) {    //  search all departures from current airport
            if (!visited[it->first]) {  //  next airport has not been visited
                previous[it->first] = current;  //  mark previous airport as current airport
                airportQueue.push(it->first);   //  enqueue next airport
                visited[it->first] = true;
            }
        }
        if (current == destination) {   //  stop once destination is reached
            break;
        }
        airportQueue.pop();
    }

    if (current != destination) { //  no path could be found between start and destination using BFS
        vector<int> T;
        return T;
    }

    //  trace back path from destination to start
    stack<int> pathId;
    while (current != start) {
        pathId.push(current);
        current = previous[current];
    }
    pathId.push(start);

    //  pushback ids into the vector
    vector<int> path;
    while (!pathId.empty()) {
        int ap = pathId.top();
        path.push_back(ap);
        pathId.pop();
    }
    for (int i : path) {
    }
    return path;
}

struct comp {
    constexpr bool operator()(
        pair<int, double> const& a,
        pair<int,double> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};
//  Performs Dijkstra's algorithm to find shortest path between start and destination airports
pair<vector<int>,double> Graph::dijkstra(int start, int destination) {
    if (graph[start].empty() || graph[destination].empty()) { //  case that no commercial flights connect start and destination
        pair<vector<int>,double> T;
        return T;
    }

    vector<int> distanceFromStart(14110,INT_MAX);   //  total distance from start to current airport
    vector<int> previous(14110,-1); //  maintains previous airport visited (with shortest distance to start)

    std::priority_queue<pair<int,double>, vector<pair<int,double>>,comp> pq;
    pq.push(make_pair(start,0.0));
  
    distanceFromStart[start] = 0;   //  distance from start to start
    previous[start] = start;    //  initialize starting airport to start

    int current;    //  unvisited airport with shortest distanceFromStart
    while (!pq.empty()) {
        std::pair<int,double> minPair = pq.top();
        pq.pop();
    
        for (list<pair<int, double>>::iterator iter = graph[minPair.first].begin(); iter != graph[minPair.first].end(); iter++){
            int neighbor = iter->first;
            double currentdisttoneighbor = iter->second;
            if (distanceFromStart[neighbor]> distanceFromStart[minPair.first]+currentdisttoneighbor){
                distanceFromStart[neighbor]=distanceFromStart[minPair.first]+currentdisttoneighbor;
                pq.push(make_pair(neighbor,distanceFromStart[neighbor]));
                previous[neighbor]=minPair.first;
            }
        }
        
    }

    if (previous[destination]==-1) { //  no path could be found between start and destination
        pair<vector<int>,double> T;
        return T;
    }

    //  trace back path from destination to start
    stack<int> pathId;
    current = destination; 
    while (current != start) {
        pathId.push(current);
        current = previous[current];
    }
    pathId.push(start);

    //  convert airport IDs
    vector<int> path;
    while (!pathId.empty()) {
        int ap = pathId.top();
        path.push_back(ap);
        pathId.pop();
    }
    pair<vector<int>,double> shortestPath(path, distanceFromStart[destination]);    //  create pair of path and total distance
    return shortestPath;
}


vector<vector<double>> Graph::normalize(vector<vector<int>> a){//normalize the adjacent matrix
    vector<vector<double>> m(a.size());//create new matrix
    for(size_t i = 0; i < a.size();i++){
        vector<double> temp(a.size());
        m[i] = temp;
    }
    for(size_t i = 0; i < a.size();i++){
        int sum = 0;
        for(size_t j = 0; j < a[0].size(); j++){
            sum += a[j][i];  //get sum of col
        }
        for(size_t j = 0; j < a[0].size(); j++){
            if(sum == 0){
                m[j][i] = (double)1.0/a.size();
            } else{
                m[j][i] = (double)a[j][i]/sum; //put value in new matrix
            }
        }
    }
    return m;
}
vector<vector<int>> Graph::adjcentMatrix(){
    return adj;
}
vector<double> Graph::pagerank(vector<vector<double>> a, vector<double> init,int time){
    vector<double> temp(a.size());
    for(int i = 0; i < time;i++){//loop 
        for(size_t row = 0; row < a.size();row++){//dot product of matrix and vector
            temp[row]=0;
            for(size_t col = 0; col < a[0].size();col++){
                temp[row]+=a[row][col]*init[col];
            }
        }
        init = temp;
    }
    return init;
}

vector<int> Graph::rankAirport(vector<double> a){
    vector<int> rank;
    for(size_t i = 0; i < a.size(); i++){
        double max = a[0];
        size_t maxindex = 0;
        for(size_t j = 0; j < a.size();j++){
            if(a[j]>max){
                max = a[j];
                maxindex = j;
            }
        }
        a[maxindex] = 0;
        rank.push_back(idx[maxindex]);
    }
    return rank;
}
size_t Graph::importance(int n,vector<int> rank){
    for(size_t i = 0; i < rank.size();i++){
        if(rank[i] == n){
            return i;
        }
    }
    return (size_t)-1;
}



int Graph::findDistance(int id1, int id2){
    if (airport.find(id1) == airport.end()|| airport.find(id2) == airport.end()){
        return 0;
    }
        double lat1 = airport.find(id1)->second.first;
        double lon1 = airport.find(id1)->second.second;
        double lat2 = airport.find(id2)->second.first;
        double lon2 = airport.find(id2)->second.second;
        double R = 6371000; //  average radius of Earth in meters
        double phi1 = lat1 * M_PI/180;  //  convert to radians
        double phi2 = lat2 * M_PI/180;
        double deltaPhi = (lat2-lat1) * M_PI/180;
        double deltaLambda = (lon2-lon1) * M_PI/180;
        double a = ( sin(deltaPhi/2)*sin(deltaPhi/2) ) + cos(phi1) * cos(phi2) * ( sin(deltaLambda/2)*sin(deltaLambda/2) );
        double c = 2 * atan2(sqrt(a), sqrt((1-a)));
        double d = R * c;
        int distance = (int)d;
    return distance;
}