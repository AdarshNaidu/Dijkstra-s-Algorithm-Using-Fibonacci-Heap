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

## Quick Analysis:- 
*  The running time complexity of Dijkstra's algorithm when implemented using Binary Heap is:-  
  ```O(VlogV+ElogV) = O(ElogV)```  
  ```VlogV``` to perform **Extract_Min**   
  ```ElogV``` to perform **Decrease Key**  


*  The running time complexity of Dijkstra’s algorithm when implemented using Fibonacci Heap is:-  
```O(|E| + |V| log |V|)```  
```VlogV``` to perform **Extract_Min**  
```E``` to perform **Decrease Key**      


*The latter is smaller for fairly dense graphs (i.e. graphs where V = o(E))*

## Some Important Links
* [Dijkstra's algorithm and priority queue good explanation](https://people.maths.bris.ac.uk/~csxam/teaching/dsa/dijkstra.pdf)
* [Fibonacci Heap explanation](https://iq.opengenus.org/fibonacci-heap/)
* [Fibonacci Heap Visualisation](https://www.cs.usfca.edu/~galles/visualization/FibonacciHeap.html)

