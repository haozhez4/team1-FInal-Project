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

TEST_CASE("Verify that if lon and la match with id #238") {
	int id = 238;
	Graph g=Graph("/workspaces/final project/project/src/ airports.dat","/workspaces/final project/project/src/route.dat");
	pair<double, double> location = g.getLocation(id);
	REQUIRE(location == pair<double,double>(31.673000335699996, 6.140439987180001));
}


