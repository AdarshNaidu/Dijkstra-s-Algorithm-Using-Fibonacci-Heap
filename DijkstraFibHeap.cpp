#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include "FibonacciHeap.h"
#include <algorithm> 
#include <chrono> 
#include <iostream> 
using namespace std; 
using namespace std::chrono;

int main(int argc, char *argv[])
{
	auto start = high_resolution_clock::now();	
	
	long n;

	if(argv[1]== NULL)
	{	
		printf("1 Argument required: DijkstraFibHeap.exe [graph file name]\n");
		printf("Example: ./Dijkstra.exe graph.dat\n");
		return 0;
	}	

	std::vector<Node*> vertices;
	std::vector<Edge*> edges;

	printf("Loading %s\n", argv[1]);
	std::ifstream indat(argv[1]);
	char inp[100];

	if(indat)
	{
		indat.getline(inp, 160);
		n = atol(inp);

		for(int j=0; j<n ; j++)
		{
			Node* v = new Node(j, 0);
			vertices.push_back(v);
		}

		printf("Vertices loaded...\n");

	
		while(!indat.eof())
		{
			memset(inp, '\0', sizeof(inp));
			indat.getline(inp, 160);

			int k=1;
			while(inp[k] != ' ' && inp[k]!='\0')
				k++;
			
			std::string inpstr = inp;
			int tail = atoi(const_cast<char*>(inpstr.substr(0, k).c_str()));
			int l=k+1;
			while(inp[l] != ' ' && inp[l]!='\0')
				l++;
			int head = atoi(const_cast<char*>(inpstr.substr(k+1, l).c_str()));
			k=l+1;
			
			while(inp[k] != ' ' && inp[k]!='\0')
				k++;

			double length = atof(const_cast<char*>(inpstr.substr(l+1, k).c_str()));

			Edge* edge = new Edge(vertices[tail], vertices[head], length);
			edge->head->addIncomingEdge(edge);
			edge->tail->addOutgoingEdge(edge);
			edges.push_back(edge);
			
		}	
	}
	else
	{
		printf("Could not open input data...\n");
		return 0;
	}

	int src;
	int dest;
	cout<<"\nEnter the source vertex: ";
	cin>>src;
	cout<<"Enter the destination: ";
	cin>>dest;


	
	vertices.push_back(new Node(dest, 0)); 
	vertices[dest]->state = LABELED;


	
	FibonacciHeap* heap = new FibonacciHeap();


	heap->insertVertex(vertices[dest]);

	
	do
	{
		Node* v = heap->deleteMin();
		
		v->state = SCANNED;

		
		for(int i = 0; i < v->incomingEdges.size(); i++)
		{
			Edge* currentEdge = v->incomingEdges[i];
			Node* headOfCurrentEdge = currentEdge->tail;

			if(headOfCurrentEdge->state != SCANNED)
				{
				if(headOfCurrentEdge->state == UNLABELED)
				{
					headOfCurrentEdge->state = LABELED;
					headOfCurrentEdge->next = v;
					headOfCurrentEdge->key = v->key + currentEdge->length;
					heap->insertVertex(headOfCurrentEdge);
				}
				else if(headOfCurrentEdge->key > v->key + currentEdge->length )
				{
					headOfCurrentEdge->next = v;
					heap->decreaseKey(v->key + currentEdge->length, headOfCurrentEdge);
				}
			}
		}
	}
	while(!heap->isEmpty());
	

	

	Node* temp = vertices[src];


	if(!temp->next)
	{
		printf("There exist no s-t paths\n");
		return 0;
	}

	int vertexCount = 0;
	
	printf("\nDistance: %d\n", (int)vertices[src]->key);
	
	while(temp)
	{
		printf("%d", temp->data);
		temp = temp->next;
		if(temp)
			printf(" -> ");

		vertexCount++;
	}


	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\n\nTime taken by function: "<< duration.count() << " microseconds" << endl;

	return 0;
}