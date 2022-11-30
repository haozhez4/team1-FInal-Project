#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

// string file_to_string(const string & filename) {
// 	ifstream text(filename);
	
// 	stringstream strStream;
// 	if (text.is_open()) {
// 		strStream << text.rdbuf();
// 	}

// 	return strStream.str();
// }


Graph::Graph(const string & airportFile, const string & routesFile){
    ifstream ifs{airportFile};
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
        index.push_back(id);
        graph.insert(pair<int, list<pair<int, double>>>(id,l));
        airport.insert(pair<int,pair<double,double>>(id,location));
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
        double d = findDistance(id1,id2);
        if (graph.find(id1) == graph.end()){
            continue;
        }
        graph.find(id1)->second.push_back(std::pair<int, double>(id2,d));
    }
}

map<int, list<pair<int, double>>> Graph::getMap() {
    return graph;
}

pair<double, double> Graph::getLocation(int id) {
    return airport.find(id)->second;
}

// //  Performs BFS begining with start
// vector<int> Graph::BFS(int start) {
//     //  Mark all airports as not visited
//     vector<bool> visited(14110);    //  highest airport ID #
//     for (unsigned i=0; i<14110; i++) {
//         visited[i] = false;
//     }
//     //  initialize BFS
//     queue<int> airportQueue;    //  queue for BFS
//     queue<int> searchQueue;  //  order of airports visited during BFS
//     airportQueue.push(start);   //  enqueue first airport
//     searchQueue.push(start);
//     int current = start;    //  current airport being visited

//     //  BFS
//     while (!airportQueue.empty()) {
//         current = airportQueue.front();
//         for (auto it=graph.find(current).begin(); it!=graph.find(current).end(); it++) {    //  search all departures from current airport
//             if (!visited[it->first]) {  //  next airport has not been visited
//                 searchQueue.push(it->first);  //  add airport to BFS search
//                 airportQueue.push(it->first);   //  enqueue next airport
//                 visited[it->first] = true;
//             }
//         }
//         airportQueue.pop();
//     }

//     vector<int> search;
//     while (!searchQueue.empty()) {
//         int ap = searchQueue.front();
//         search.push_back(ap);
//         searchQueue.pop();
//     }
//     return search;
// }


// vector<vector<double>> normalize(vector<vector<double>> a){
//     for(size_t i = 0; i < a.length();i++){
//         int sum = 0;
//         for(size_t j = 0; j < a[0].length()){
//             sum+=a[j][i];
//         }
//         for(size_t j = 0; j < a[0].length()){
//             a[j][i] /= a[j][i];
//         }
//     }
//     return a;
// }

// vector<double> pagerank(vector<vector<double>> a, vector<double> init){
//     vector<double> temp(a.length());
//     for(int i = 0; i < 10;i++){
//         for(int row = 0; row < a.length();row++){
//             temp[row]=0;
//             for(col = 0; col < a[0].length();col++){
//                 temp[row]+=a[row][col]*init[row];
//             }
//         }
//         init = temp;
//     }
//     return init;
// }

// vector<int> rankAirport(vector<double> a, int num){
//     vector<int> indexRank;
//     for(int i = 0; i < num; i++){
//         int max = a[0];
//         int index = 0;
//         for(int j = 0; j < a.length();j++){
//             if(a[j]>max){
//                 max = a[j];
//                 index = j;
//             }
//         }
//         a[index] = 0;
//         indexRank.push_back(j+1)
//     }
//     return indexRank;
// }

double Graph::findDistance(int id1, int id2){
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
    return d;
}