# CS 225 Fall 2022 Final Project
This project explores the most efficient (shortest) path through the utilization of BFS, Dijkstra’s algorithm, and A* Search. The goal of this project is to gain insight into how people can travel between airports with the shortest route possible. The OpenFlights dataset used in this project can be found at https://openflights.org/data.html.

## Team Members: Harry Xu && Dylan Zhuang && Logan Cheng && Andy Xu

## Links
Final Presentation Video: 
Final Presentation Powerpoint:
Final Report:

## File Descriptions
* main.cpp: Contains the user interface.
* graph.cpp: Contains the constructors and algorithms needed to compute
*             1.the shortest route from a chosen airport to a chosen destination;
*             2.the route with the fewest stopovers from a chosen airport to a chosen destination;
*             3.the popularity of a chosen airport.
* graph.h: The header file for graph.cpp.
* airports.dat: Contains information about each airport.
* route.dat: Contains information about all the routes between different airports.
* test.cpp: Contains all the test cases for this project.

## Instructions on Running the Program

To clone this repository to your local device, run the following command in your terminal.
```
git clone https://github.com/haozhez4/team1-FInal-Project.git
```

Run the following command to make the build directory.
```
mkdir build
cd build
```

Then to initiate it run:
```
cmake ..
```
## Execution of the Program

To execute the program, run the command:
```
make main
./main
```

The following prompt will show up:
```
Choose an option, 1: Find the flight path with the fewest stopovers, 2: Find the flight path with the shortest distance between the airports
```
Run the command ``` 1 ``` or ``` 2 ``` depending on the result you seek.

Enter the ID of the starting airport after the prompt:
```
Enter starting airport
```

And enter the ID of the destination airport after the prompt:
```
Enter destination airport
```



## Description of Test Cases

To run the test cases, enter the following commands:
```
make test
./test
```
The test cases we provided cover the following:
* Constructing a Graph
* Constructing an Airport
* Find Distance Algorithm
* BFS Traversal
* Djikstra's Algorithm
* Pagerank Algorithm
* Airport Rank Algorithm
