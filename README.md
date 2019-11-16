# Dijkstra-s-Algorithm-Using-Fibonacci-Heap
Dijkstra's Algorithm usinig Fibonacci Heap

## About Project:-

* The program takes input from an external file.
* The file contains the number of vertices, and the a list of edges in the following format (tail, head, length) 
* The source and destination vertices are taken as input from the terminal.
* Dijkstra’s algorithm is run of the created graph.
* Distance, path, and time taken are displayed in the terminal.


## Files in the project:-

* FibonacciHeap.cpp : Fibonacci Heap Data Structure
* DijkstraFibHeap.cpp : Dijkstra's Implemented using Fibonacci Heap
* BinaryHeap.cpp : Binary Heap Data Structure 
* DijkstraBinaryHeap.cpp : Dijkstra's Implemented using Binary Heap

## How to run the project:-

### Fibonacci Heap Implementation
* ```g++ DijkstraFibHeap.cpp FibonacciHeap.cpp -o fib```
* ```./fib.exe graph.dat```

### Binary Heap Implementation
* ```g++ DijkstraBinHeap.cpp BinaryHeap.cpp -o bin```
* ```./bin.exe graph.dat```
