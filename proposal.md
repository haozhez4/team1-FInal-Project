Proposal

## Leading Question 
With the advancement of technology, the word "efficiency" is particularly important in the 21st century. Today, with the birth of the airplane, it is commonplace to flash from one end of the globe to the other in a matter of hours. However, there’s not a road in the air which airplanes can drive along. In this project, we are trying to find the most efficient(shortest) path through algorithms listed below. The goal of this project is to gain insight into how humans can travel between airports by the shortest route by exploring the OpenFlights dataset. (https://openflights.org/data.html). 

## Dataset Acquisition


## Data Format
In this project, we will use the data from the OpenFlights dataset. We will create a graph that can hold airports and the routes between them. We will make the airports as nodes on the graph. Then we can calculate the distance between the airports using the airport dataset. We can treat these data as the weight of the edge. The dataset contains 67663 routes between 3321 airports on 548 airlines spanning the globe. We are planning to use all parts of the dataset. 

## Data Correction
If an error occurs due to invalid or uninterpretable data, we would treat it as faulty and it would be ignored.

## Data Storage
We will download all of our data from OpenFlights (airports.dat and routes.dat). We would store it on our GitHub repository and create a graph to store our data. We will use adjacency list to storage the graph. The big O of adjacency list is O(n + m). n is represent nodes and m is edges.

## Algorithm 

The airports are the nodes of the graph. The distance between airports is the weight of the edge. We will use a BFS traversal to visit all the nodes in the graph. We will choose the starting point, the ending point and some nodes that we need to pass. Then we will use Dijkstra’s algorithm to find out the shortest path between two airports. In addition, we would also use the Landmark Path, which would also calculate the shortest path between airports. Besides, the Landmark Path returns a shortest path that contains target airports. The input of the two algorithms should be nodes picked from the direct graph we are using to store the information of all the airports and the output is a path of edges stored in a vector of Edge objects. We expect the big O of the two algorithms to be O(V^2).


## Timeline

Week 1 NOV 10: setup the outline of project
Week 2 NOV 17: test case of two algorithms and complete Dijkstra algorithm and verified with test cases
Week 3 NOV 24: complete Landmark Path algorithm and verified with test cases
Week 4 DEC 1: complete presentation and project report 
