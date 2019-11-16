#include<iostream> 
#include<climits> 
#include "BinaryHeap.h"
using namespace std; 


void swap(Node **x, Node **y);


Edge::Edge(Node* tail, Node* head, double length)
{
	this->tail = tail;
	this->head = head;
	this->length = length;
}

Node::Node(int data, int key)
{
	this->key = key;
	this->data = data;
	
	next = NULL;
	state = UNLABELED;
}

Node::Node()
{
	
	next = NULL;
	
	state = UNLABELED;
}
 

 void Node::addIncomingEdge(Edge * edge)
{
	incomingEdges.push_back(edge);
}

void Node::addOutgoingEdge(Edge * edge)
{
	outgoingEdges.push_back(edge);
}


MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new Node*[cap]; 
} 


void MinHeap::insertKey(Node * k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	
	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	
	while (i != 0 && harr[parent(i)]->key > harr[i]->key) 
	{ 
	
    swap(&harr[i], &harr[parent(i)]);
	i = parent(i); 
	} 
} 


void MinHeap::decreaseKey(int new_val, Node * node) 
{ 
    int i;
	
    node->key = new_val;
    for(i = 0; i < capacity; i++){
        if(harr[i] == node) break;
    }
    while( i != 0 && harr[parent(i)]->key > harr[i]->key){
       
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
} 


Node*  MinHeap::extractMin() 
{ 
	if (heap_size <= 0) 
		return NULL; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	
	Node* root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 

void MinHeap::MinHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l]->key < harr[i]->key) 
		smallest = l; 
	if (r < heap_size && harr[r]->key < harr[smallest]->key) 
		smallest = r; 
	if (smallest != i) 
	{ 
		 
        swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest); 
	} 
} 


void swap(Node ** x, Node ** y){
    Node * temp = *x;
    *x = *y;
    *y = temp;
}
