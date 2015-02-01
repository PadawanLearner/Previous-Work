#ifndef TREE_H
#define TREE_H

#include "node.h"

using namespace std;

class tree{

public:

	tree::tree(node* rootNode);
	node* tree::getRoot();
	void tree::setNullRoot();
	void tree::setRoot(node* newRoot);

	//traversal
	void tree::preOrder(node* tempRoot);

	//search
	node* tree::search(node* x, int k);

	//insert
	void tree::insertNode(tree &subTree, node* z);

	//delete
	void tree::deleteNode(tree &subTree, node* z);

	//successor
	node* tree::successor(node* aNode);
	node* tree::successorHelper(node* aNode);

	//max
	node* tree::max();
	//min
	node* tree::min();

	//height
	int tree::maxHeight(node* tempRoot, int max);

	int tree::computeBalanceFactor(node* myNode);

private:
	node* root;



};







#endif