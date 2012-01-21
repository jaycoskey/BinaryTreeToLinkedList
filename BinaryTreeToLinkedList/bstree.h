// Jay Coskey, January 2012, Seattle

#ifndef __BSTREE__
#define __BSTREE__

class Node;
class NodeActionAccumulator;

using namespace std;

class BsTree {
public:
    BsTree();
	void inorderTraversal(NodeActionAccumulator& naa);
    void insert(int value, Node** nodePP = NULL);
	void insert(vector<int>& values);
	void print();

	Node* rootP;

	friend ostream& operator<<(ostream& o, BsTree const& tree);
};
#endif // __BSTREE__