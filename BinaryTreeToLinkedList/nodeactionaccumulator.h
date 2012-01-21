// Jay Coskey, January 2012, Seattle

#ifndef __NODEACTIONACCUMULATOR_H__
#define __NODEACTIONACCUMULATOR_H__

class DlList;
class Node;

class NodeActionAccumulator {
  public: 
    NodeActionAccumulator();
    DlList& getList();
    void nodeAction(Node* nodeP);
private:
	void	convertTreeToList(Node* nodeP);
	int		actionCount;
	Node*	headP;
	bool	isLastCallMade;
	DlList* listP;
	Node*	prevNodeP;
};

#endif // __NODEACTIONACCUMULATOR_H__