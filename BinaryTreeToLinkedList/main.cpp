// Jay Coskey, January 2012, Seattle

#include <iostream>
#include <string>
#include <vector>

#include "bstree.h"
#include "dllist.h"
#include "nodeactionaccumulator.h"

using namespace std;

void pause(string prompt = "Press enter to continue: ")
{ 
	cout << prompt;
	cout.flush();
	static char dummy[256];
	cin.getline(dummy, 255);
	static string separator = "--------------------";
	cout << separator << endl;
}

int main()
{
	int vals[] = { 5, 3, 7, 1, 4, 6, 9, 0, 2, 8, 10 };
	vector<int> values;
	for (int i = 0; i < (sizeof(vals) / sizeof(vals[0])); i++) {
		values.push_back(vals[i]);
	}
	BsTree tree;
	tree.insert(values);

    cout << "Inorder tree traversal:" << endl;
    cout << tree << endl;
	pause();

	cout << "Inorder tree traversal, using NodeActionAccumulator:" << endl;
	NodeActionAccumulator naa;
	tree.inorderTraversal(naa);
	pause();

	cout << "Traversal of list created by NodeActionAccumulator:" << endl << "  ";
	DlList& list = naa.getList();
	cout << list << endl;
	pause();

	cout << "Traversal of previous list, reversed:" << endl << "  ";
	list.reverse();
	cout << list << endl;
	cout << endl;
	pause("Press enter to exit: ");
}