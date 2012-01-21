// Jay Coskey, January 2012, Seattle

#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

using namespace std;

class Node {
  public:
    Node (int value, Node* left /* = NULL */, Node* right /* = NULL */);
    static int nextId;
    int id;
    Node* leftP;
    Node* rightP;
    int data;
	friend ostream& operator<<(ostream& o, Node const* nodeP);
};
#endif // __NODE_H__