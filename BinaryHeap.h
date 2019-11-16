#include <stdio.h>
#include <vector> 

enum State
{
	LABELED, UNLABELED, SCANNED
};

class Edge;

class Node
{
private:
public:
	Node * next;

	Node(int data, int key);
	Node();

	int data;
	int key;


	std::vector<Edge*> incomingEdges;
	std::vector<Edge*> outgoingEdges;

	State state;

	
	bool remove();

	void addIncomingEdge(Edge * edge);
	void addOutgoingEdge(Edge * edge);

};

class Edge
{
private:
public:
	Node* tail;
	Node* head;
	double length;

	Edge(Node* tail, Node* head, double length);
};



class MinHeap 
{ 
	Node **harr; 
	int capacity; 
	
public: 
	int heap_size;
	 
	MinHeap(int capacity); 
	
	void MinHeapify(int ); 

	int parent(int i) { return (i-1)/2; } 

	int left(int i) { return (2*i + 1); } 

	int right(int i) { return (2*i + 2); } 

	Node * extractMin(); 

	void decreaseKey(int i, Node* new_val); 
	
	int getMin() { return harr[0]->key; } 

	void insertKey(Node * k); 
};

