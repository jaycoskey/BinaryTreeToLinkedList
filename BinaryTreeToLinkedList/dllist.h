// Jay Coskey, January 2012, Seattle

#ifndef __DLLIST__
#define __DLLIST__

class Node;

using namespace std;

// Unimplemented: iterators, begin(), end(), etc.
// Unimplemented: pop_left(), pop_right(), push_left(), push_right(), size(), etc.
class DlList {
  public:
    DlList(Node* hd = NULL, Node* tl = NULL);
	void reverse();
    Node* headP;
    Node* tailP;
    friend ostream& operator<<(ostream& o, DlList const& listP);
};
#endif // __DLLIST__