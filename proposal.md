Proposal

## Leading Question 
With the advancement of technology, the word "efficiency" is particularly important in the 21st century. Today, with the birth of the airplane, it is commonplace to flash from one end of the globe to the other in a matter of hours. However, there’s not a road in the air which airplanes can drive along. In this project, we are trying to find the most efficient(shortest) path through algorithms listed below. The goal of this project is to gain insight into how humans can travel between airports by the shortest route by exploring the OpenFlights dataset. (https://openflights.org/data.html). We will use BFS, Dijkstra’s algorithm, and A* Search in our project.

## Dataset Acquisition


## Data Format
In this project, we will use the data from the OpenFlights dataset. We will create a graph that can hold airports and the routes between them. We are going to download airports.dat and routes.dat from the OpenFlights dataset. In airports.dat, we are going to use the "airport ID", "latitude", and "longitude" conlumn contained in the data, and in routes.dat, the "source airport ID" and "destination airport ID" will be used. We will make the airports as nodes on the graph. Then we can calculate the distance between the airports from the longitude and latitude. We can treat these data as the weight of the edge. The dataset contains 67663 routes between 3321 airports on 548 airlines spanning the globe. We are planning to use all parts of the dataset. 

## Data Correction
If an error occurs due to invalid or uninterpretable data, we would treat it as faulty and it would be ignored.

## Data Storage
We will download all of our data from OpenFlights (airports.dat and routes.dat). We would store it on our GitHub repository and create a graph to store our data. We will use adjacency list to storage the graph. The airport will stored in the array of node, and the distance between airports will stored in the array of edge. The big O of adjacency list is O(n + m). n is represent nodes and m is edges. The space complexity of both Dijkstra’s algorithm and A* Search is O(V^2).

## Algorithm 

The airports are the nodes of the graph. The distance between airports is the weight of the edge. We will use a BFS traversal to visit all the nodes in the graph. We will choose the starting point, the ending point and some nodes that we need to pass. Then we will use Dijkstra’s algorithm to find out the shortest path between two airports. Then, we will write the A* Search, which use a specific-goal-directed heuristic. Compared to Dijkstra's algorithm, the A* algorithm only finds the shortest path from a specified source to a specified goal, and not the shortest-path tree from a specified source to all possible goals. The input of the two algorithms should be nodes picked from the direct graph we are using to store the information of all the airports and the output is a path of edges stored in a vector of Edge objects. We expect the big O of the Dijkstra’s algorithm to be O(|E|+|V|log|V|). The time complexity of A* depends on the heuristic. In the worst case of an unbounded search space, the number of nodes expanded is exponential in the depth of the solution (the shortest path) d: O(bd), where b is the branching factor.


## Timeline

Week 1 NOV 10: setup the outline of project
Week 2 NOV 17: test case of two algorithms and complete Dijkstra algorithm and verified with test cases
Week 3 NOV 24: complete A* Path algorithm and verified with test cases
Week 4 DEC 1: complete presentation and project report 
