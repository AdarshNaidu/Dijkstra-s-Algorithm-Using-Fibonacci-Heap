#include "FibonacciHeap.h"
#include <vector>


Edge::Edge(Node* tail, Node* head, double length)
{
	this->tail = tail;
	this->head = head;
	this->length = length;
}


Node::Node(int data, double key)
{
	this->key = key;
	this->data = data;
	parent = NULL;
	children = NULL;
	leftSibling = NULL;
	rightSibling = NULL;
	next = NULL;
	rank = 0;
	state = UNLABELED;
}

Node::Node()
{
	parent = NULL;
	children = NULL;
	leftSibling = NULL;
	rightSibling = NULL;
	next = NULL;
	rank = 0;
	state = UNLABELED;
}

bool Node::addChild(Node *node)
{
	if(children != NULL)
		children->addSibling(node);
	else
	{
		children = node;
		node->parent = this;
		rank = 1;
	}

	return true;
}

bool Node::addSibling(Node *node)
{
	Node* temp = rightMostSibling();
	if(temp == NULL)
		return false;

	temp->rightSibling = node;
	node->leftSibling = temp;
	node->parent = this->parent;
	node->rightSibling = NULL;

	if(parent)
		parent->rank++;

	return true;
}

bool Node::remove()
{
	if(parent)
	{
		parent->rank--;
		if(leftSibling)
			parent->children = leftSibling;
		else if(rightSibling)
			parent->children = rightSibling;
		else
			parent->children = NULL;
	}	
	
	if(leftSibling)
		leftSibling->rightSibling = rightSibling;
	if(rightSibling)
		rightSibling->leftSibling = leftSibling;
	
	leftSibling = NULL;
	rightSibling = NULL;
	parent = NULL;

	return true;
}

void Node::addIncomingEdge(Edge * edge)
{
	incomingEdges.push_back(edge);
}

void Node::addOutgoingEdge(Edge * edge)
{
	outgoingEdges.push_back(edge);
}


Node* Node::leftMostSibling()
{
	if(this == NULL)
		return NULL;

	Node* temp = this;
	while(temp->leftSibling)
		temp = temp->leftSibling;
	return temp;
}

Node* Node::rightMostSibling()
{
	if(this == NULL)
		return NULL;

	Node* temp = this;
	while(temp->rightSibling)
		temp = temp->rightSibling;
	return temp;
}



FibonacciHeap::FibonacciHeap()
{
	minRoot = NULL;
}

FibonacciHeap::FibonacciHeap(Node *root)
{
	this->minRoot = root;
	minRoot->parent = NULL;
	minRoot->children = NULL;
	minRoot->leftSibling = NULL;
	minRoot->rightSibling = NULL;
	minRoot->rank = 0;
}

FibonacciHeap::~FibonacciHeap()
{
	delete[] rootListByRank;
}

bool FibonacciHeap::isEmpty()
{
	return (minRoot == NULL);
}

bool FibonacciHeap::insertVertex(Node * node)
{
	if(node == NULL)
		return false;

	if(minRoot == NULL)
		minRoot = node;
	else
	{
		minRoot->addSibling(node);
		if(minRoot->key > node->key)
			minRoot = node;
	}
	return true;
}

Node* FibonacciHeap::findMin()
{
	return minRoot;
}

Node* FibonacciHeap::deleteMin()
{
	Node *temp = minRoot->children->leftMostSibling();
	Node *nextTemp = NULL;

	while(temp != NULL)
	{
		nextTemp = temp->rightSibling; 
		temp->remove();
		minRoot->addSibling(temp);
		temp = nextTemp;
	}

	temp = minRoot->leftMostSibling();

	if(temp == minRoot)
	{
		if(minRoot->rightSibling)
			temp = minRoot->rightSibling;
		else
		{
			Node* out = minRoot;
			minRoot->remove();
			minRoot = NULL;
			return out;
		}
	}
	Node* out = minRoot;
	minRoot->remove();
	minRoot = temp;

	for(int i=0; i<100; i++)
		rootListByRank[i] = NULL;
	
	while(temp)
	{
		if(temp->key < minRoot->key)
		{
			minRoot = temp;
		}

		nextTemp = temp->rightSibling;		
		link(temp);
		temp = nextTemp;
	}

	return out;	
}

bool FibonacciHeap::link(Node* root)
{
	if(rootListByRank[root->rank] == NULL)
	{
		rootListByRank[root->rank] = root;
		return false;
	}
	else
	{
		Node* linkVertex = rootListByRank[root->rank];
		rootListByRank[root->rank] = NULL;
		
		if(root->key < linkVertex->key || root == minRoot)
		{
			linkVertex->remove();
			root->addChild(linkVertex);
			if(rootListByRank[root->rank] != NULL)
				link(root);
			else
				rootListByRank[root->rank] = root;
		}
		else
		{
			root->remove();
			linkVertex->addChild(root);
			if(rootListByRank[linkVertex->rank] != NULL)
				link(linkVertex);
			else
				rootListByRank[linkVertex->rank] = linkVertex;
		}
		return true;
	}
}


void FibonacciHeap::decreaseKey(double delta, Node* vertex)
{
	vertex->key = delta;

	if(vertex->parent != NULL) 
	{
		vertex->remove();
		minRoot->addSibling(vertex);		
	}
	if(vertex->key < minRoot->key)
		minRoot = vertex;
}
