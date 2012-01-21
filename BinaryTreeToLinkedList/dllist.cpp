// Jay Coskey, January 2012, Seattle

#include<algorithm>
#include <iostream>

#include "dllist.h"
#include "node.h"
#include "util.h"

using namespace std;

DlList::DlList(Node* hd /* = NULL */, Node* tl /* = NULL */) : headP(hd), tailP(tl)
{}

void DlList::reverse()
{
	for (Node *curP = headP; curP !=  NULL; curP = curP->leftP)
	{
		swap(curP->leftP, curP->rightP);
	}
	swap(headP, tailP);
}

ostream&
operator<<(ostream& o, DlList const& list)
{
    for (Node* nodeP = list.headP; nodeP != NULL; nodeP = nodeP->rightP) {
        o << nodeP << ", ";
    }
    return o;
}