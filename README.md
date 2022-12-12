# CS 225 Fall 2022 Final Project
This project explores the most efficient (shortest) path through the utilization of BFS, Dijkstra’s algorithm, and A* Search. The goal of this project is to gain insight into how people can travel between airports with the shortest route possible. The OpenFlights dataset used in this project can be found at https://openflights.org/data.html.

## Team Members: Harry Xu && Dylan Zhuang && Logan Cheng && Andy Xu

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
make???
```

The following prompt will show up:
```
Choose an option, 1: Find the flight path with the fewest stopovers, 2: Find the flight path with the shortest distance between the airports
```
Run the command ``` 1 ``` or ``` 2 ``` depending on the result you seek.

## Description of Test Cases

To run the test cases, enter the following commands:
```
make test
./test
```
