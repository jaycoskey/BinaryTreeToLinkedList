// Jay Coskey, January 2012, Seattle

#include <iostream>
#include <stdexcept>

#include "dllist.h"
#include "node.h"
#include "nodeactionaccumulator.h"

using namespace std;

NodeActionAccumulator::NodeActionAccumulator()
{
	actionCount    = 0;
	headP          = NULL;
	isLastCallMade = false;
	listP          = NULL;
	prevNodeP      = NULL;
}

DlList&
NodeActionAccumulator::getList()
{
	if (!isLastCallMade) {
		throw new runtime_error("Error: node action calls still in progress");
	}
	DlList* list = new DlList(headP, prevNodeP);
	return *list;
}

void
NodeActionAccumulator::nodeAction(Node* nodeP)
{
	if (isLastCallMade == true) {
		throw new runtime_error("Error: Re-use of NodeActionAccumulator not supported");
	}
	convertTreeToList(nodeP);
}

void
NodeActionAccumulator::convertTreeToList(Node* nodeP)
{
	// cout << "convertTreeToList called with id #" << ((nodeP == NULL) ? -1 : nodeP->id) << endl;
	if (nodeP != NULL) {
		switch (actionCount) {
		case 0:		// First call
			headP = nodeP;
			cout << "Left-most node: " << nodeP << endl << "  Middle nodes: ";
			nodeP->leftP = NULL;
			break;
		case 1:		// Middle calls
			prevNodeP->rightP = nodeP;
			break;
		default:
			cout << prevNodeP << " ";	// Only for second & later calls
			prevNodeP->rightP = nodeP;
		}
		nodeP->leftP = prevNodeP;
		actionCount++;
		prevNodeP = nodeP;
	} else {							// Last call.  Some would argue that this should be a separate method.
		isLastCallMade = true;
		if (prevNodeP != NULL) {
			cout << endl << "Right-most node: " << prevNodeP << endl;
			prevNodeP->rightP = NULL;
		}
	}
}