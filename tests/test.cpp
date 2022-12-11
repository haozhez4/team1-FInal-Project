#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <graph.h>
using namespace std;

TEST_CASE("Verify that if lon and la match with id #239") {
	int id = 239;
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
	pair<double, double> location = g.getLocation(id);
	REQUIRE(location == pair<double,double>(27.250999450699997, 2.51202011108));
}

TEST_CASE("Verify graph with id#238") {
	
	list<pair<int, double>> target;
	target.push_back(make_pair(210, 619368));
	target.push_back(make_pair(221, 513737));
	target.push_back(make_pair(224, 300383));
	target.push_back(make_pair(244, 525499));
	target.push_back(make_pair(231, 764352));
	target.push_back(make_pair(502, 2226909));

	int id = 238;
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
	list<pair<int, double>> graph = g.getMap(id);

	REQUIRE(graph == target);
}


TEST_CASE("Verify that findDistance works with id #238 and id #239") {
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
    int distance = g.findDistance(238, 239);
    REQUIRE(distance == 604189);
}
TEST_CASE("Verify that findDistance works with id #238 and id #210") {
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
    int distance = g.findDistance(238, 210);
    REQUIRE(distance == 619368);
}
TEST_CASE("Verify that findDistance works with id #238 and id #221") {
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
    int distance = g.findDistance(238, 221);
    REQUIRE(distance == 513737);
}
TEST_CASE("Verify that findDistance works with id #238 and id #224") {
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
    int distance = g.findDistance(238, 224);
    REQUIRE(distance == 300383);
}
TEST_CASE("Verify that findDistance works with id #238 and id #244") {
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
    int distance = g.findDistance(238, 244);
    REQUIRE(distance == 525499);
}
TEST_CASE("Verify that findDistance works with id #238 and id #231") {
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
    int distance = g.findDistance(238, 231);
    REQUIRE(distance == 764352);
}
TEST_CASE("Verify that findDistance works with id #238 and id #502") {
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
    int distance = g.findDistance(238, 502);
    REQUIRE(distance == 2226909);
}

//The data is copied from CS357 and proved correct
TEST_CASE("test pagerank") {
    Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
	vector<vector<int>> m
    {
        {0,0,0,1,0,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,1,0,0,0},
        {0,0,1,0,0,0},
        {1,0,1,0,1,0}
    };
    vector<vector<double>> n
    {
        {0,0,0,1,0,1},
        {0.5,0,0,0,0,0},
        {0,0.5,0,0,0,0},
        {0,0.5,1.0/3.0,0,0,0},
        {0,0,1.0/3.0,0,0,0},
        {0.5,0,1.0/3.0,0,1,0}
    };
    REQUIRE(g.normalize(m) == n);

    vector<double> v{0.3529426146,0.1764702189,0.0882351932,0.1176473568,0.0294121636,0.235292453};
    vector<double> init{1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0};
	bool b = true;
    vector<double> result = g.pagerank(n, init, 20);
	for(int i = 0;i < 6;i++){
		if((v[i]-result[i])<-0.00001||(v[i]-result[i])>0.00001){
			b = false;
		}
	}
    REQUIRE(b == true);
}

TEST_CASE("rank airport"){
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
	vector<double> v{0.3529426146,0.1764702189,0.0882351932,0.1176473568,0.0294121636,0.235292453};
	vector<int> r = g.rankAirport(v);
	vector<int> t{1,6,2,4,3,5};
	REQUIRE(r == t);
}


// TEST_CASE("Test BFS Algorithm") {
// 	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
//   	vector<int> vect;

//     REQUIRE(distance == 2226909);
// }



