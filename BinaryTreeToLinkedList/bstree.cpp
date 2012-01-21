// Jay Coskey, January 2012, Seattle

#include <iostream>
#include <stack>
#include <vector>

#include "bstree.h"
#include "node.h"
#include "nodeactionaccumulator.h"

BsTree::BsTree() : rootP(NULL) { }

// Here's a non-recursive implementation, just for kicks
void
BsTree::inorderTraversal(NodeActionAccumulator& naa) 
{
	if (this->rootP == NULL) { return; }
	stack<Node*> nodes = *(new stack<Node*>());
	Node* nodeP;
	for (nodeP = this->rootP; nodeP != NULL; nodeP = nodeP->leftP) {
		nodes.push(nodeP);
	}
	while (!nodes.empty()) {
		nodeP = nodes.top();
		nodes.pop();
		naa.nodeAction(nodeP);	// Call action function
		nodeP = nodeP->rightP;
		while (nodeP != NULL) {
			nodes.push(nodeP);
			nodeP = nodeP->leftP;
		}
	}
	naa.nodeAction(NULL);		// No more actions
}

// <param>nodePP</param> points to the root pointer of the tree that <param>value</param> is to be added to.
void
BsTree::insert(int value, Node** nodePP /* = NULL */)
{
	if (nodePP == NULL) { nodePP = &rootP; }
	Node* nodeP = *nodePP;
	if (nodeP == NULL) {
		*nodePP = new Node(value, NULL, NULL);
	} else {
		if (value <= nodeP->data) {
			insert(value, &(nodeP->leftP));
		} else {
			insert(value, &(nodeP->rightP));
		}
	}
}

void BsTree::insert(vector<int>& values) {
	for (vector<int>::const_iterator p = values.begin(); p != values.end(); p++)
	{
		insert(*p);
	}
}

void
BsTree::print()
{
	stack<Node> nodes = *(new stack<Node>());
}

// Node: Instead of this, use BsTree's inorderTraversal() 
ostream&
operator<<(ostream& o, BsTree const& tree)
{
    Node* nodeP = tree.rootP;
    if (nodeP == NULL) {
        return o << endl << "EMPTY" << endl;
    }
    stack<Node*> nodes = *(new stack<Node*>());
    while (nodeP != NULL) {
        nodes.push(nodeP);
        nodeP = nodeP->leftP;
    }
    while (!nodes.empty()) {
        nodeP = nodes.top();
        nodes.pop();
        o << nodeP << ", ";
        nodeP = nodeP->rightP;
        while (nodeP != NULL) {
            nodes.push(nodeP);
            nodeP = nodeP->leftP;
        }
    }
    return o;
}