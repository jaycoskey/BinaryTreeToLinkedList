// Jay Coskey, January 2012, Seattle

#include <iostream>

#include "node.h"

using namespace std;

Node::Node(int value, Node* left = NULL, Node* right = NULL)
{
	this->data = value;
	this->id = nextId++;
	this->leftP = left;
	this->rightP = right; 
}

int Node::nextId = 0;

ostream&
operator<<(ostream& o, Node const* nodeP)
{
    return o << "#" << nodeP->id << "(" << nodeP->data << ")";
}