#include "tree.h"


tree::tree(node* rootNode){
	root = rootNode;
};

node* tree::getRoot(){
	return root;
};

void tree::setNullRoot(){
	
	root = NULL;
};

void tree::preOrder(node* tempRoot){

	if (tempRoot != NULL){

		//work on root
		//set the balance factor:
		tempRoot->setBalanceFactor(computeBalanceFactor(tempRoot));
		//output:
		cout << endl << "NODE:	key= " << tempRoot->getKey() << ", balance factor= " << tempRoot->getBalanceFactor() << endl;
		//work on left
		preOrder(tempRoot->getLeftChild());
		//work on right
		preOrder(tempRoot->getRightChild());
	}
			
	return;
};

void tree::setRoot(node* newRoot){
	root = newRoot;
	
};

node* tree::max(){
	node* temp = getRoot();

	while (temp->getRightChild() != NULL)
		temp = temp->getRightChild();

	return temp;
};

node* tree::min(){

	node* temp = getRoot();

	while (temp->getLeftChild() != NULL)
		temp = temp->getLeftChild();

	return temp;

};

int tree::maxHeight(node* tempRoot, int max){
	
	
	if (tempRoot != NULL){

		//work on root
		if (tempRoot->getHeight() > max){
			max = tempRoot->getHeight();
		}
		//work on left
		max  = maxHeight(tempRoot->getLeftChild(), max);
		//work on right
		max =  maxHeight(tempRoot->getRightChild(), max);
	}


	return max;
}


node* tree::search(node* x, int k){


	if (x == NULL)
		return x;

	if ( x->getKey() == k)
		return x;
	
	if (k < x->getKey())
		search(x->getLeftChild(), k);
	else
		search(x->getRightChild(), k);
};

void tree::insertNode(tree &subTree, node* z){

	node* y = NULL; 
	node* x = subTree.getRoot();

	//re-establish x down through the tree until you hit a null, ie you cannot look for further spots
	while (x != NULL ){
		y = x;
		//traverse down the tree, left or right depending.  re-establish x each time for next loop iteration
		if (z->getKey() < x->getKey()){
			x = x->getLeftChild();
		}
		else{
			x = x->getRightChild();
		}
	}

	//now we are in the right spot. set the parent of our to-be-inserted node as y (served as the the base "root" as we traversed down the tree)
	z->setParent(y);

	//the above loop did not run, i.e this is the first node being inserted case:
	if (y == NULL){
		subTree.setRoot(z);
		//set root height to zero, this is the only height we will have to specifically define.  all others will be +1'ed from the root height (see below) 
		z->setHeight(0);
		//z->setBalanceFactor(computeBalanceFactor(z));
		
	}
	//this is the general case, 
	//we have now traveresed down to the correct spot, we now insert the new node z from the perspective of y, which is the variable version of the to be inserted node's parent (1 above where z will go)
	else{
		if (z->getKey() < y->getKey())
			y->setLeftChild(z);
		else
			y->setRightChild(z);

		//set the inserted node's height to +1 of it its parents height, since the parent is always just one above the child
		z->setHeight(y->getHeight() + 1);
		//z->setBalanceFactor(computeBalanceFactor(z));
	}


	

	return;
};


//delete was frickin hard
void tree::deleteNode(tree &subTree, node* z){

	node* x = new node;
	node* y = new node;

	if (z->getLeftChild() == NULL || z->getRightChild() == NULL)
		y = z;
	else{
		y = successor(z);
	}

	if (y->getLeftChild() != NULL)
		x = y->getLeftChild();
	else
		x = y->getRightChild();

	if (x != NULL)
		x->setParent(y->getParent());

	if (y->getParent() == NULL)
		subTree.setRoot(x);

	else{

		if (y == y->getParent()->getLeftChild())
			y->getParent()->setLeftChild(x);
		else
			y->getParent()->setRightChild(x);
	}


	if (y != z){
		//*z = *y;
		z->setKey(y->getKey());
		//hmmmmm
		z->setHeight(y->getHeight());
		//z->setBalanceFactor(computeBalanceFactor(z));
	}



	return;

};

node* tree::successor(node* aNode){

	//search the subtree of the node for its successor:
	if (successorHelper(aNode) != NULL)
		return successorHelper(aNode);


	//the node has no successor, ie it is the root, or it the maximum node
	else if (max() == aNode)
		return aNode;

	//successor wasnt found in subtree, therefore it must be somewhere above the node:
		//case 1
	else if (aNode->getParent()->getKey() <= aNode->getKey()){

		node* temp = aNode->getParent();

		//equals case:
		if (aNode->getKey() == temp->getKey()){
			while (temp->getKey() == aNode->getKey())
				temp = temp->getParent();
			return temp;
		}
		else{
			while (aNode->getKey() > temp->getKey())
				temp = temp->getParent();
			return temp;
		}
	}

		//case 2, easy case. the immediate parent is the successor, ie it is greater than the node we are testing for succession
	else 
		return aNode->getParent();
};


node* tree::successorHelper(node* aNode){

	node* goRight = aNode->getRightChild();

	if (goRight != NULL){

		node* temp = goRight;
		goRight = goRight->getLeftChild();

		while (goRight != NULL){
			temp = goRight;
			goRight = goRight->getLeftChild();
		}

		return temp;
	}
	else
		return NULL;

};


int tree::computeBalanceFactor(node* myNode){
	if (myNode->getLeftChild() == NULL && myNode->getRightChild() == NULL){
		return 0;
	}


	else if (myNode->getRightChild() == NULL){
		return ((maxHeight(myNode,0) - myNode->getHeight()) - 0);
	}

	else if (myNode->getLeftChild() == NULL){
		return (0 - (maxHeight(myNode, 0) - myNode->getHeight()));
	}

	else{
		return(
			(maxHeight(myNode->getLeftChild(), 0) - myNode->getLeftChild()->getHeight())
			-
			(maxHeight(myNode->getRightChild(), 0) - myNode->getRightChild()->getHeight())
			);
	}
		


};
//int node::getBalanceFactor(tree &myTree){
/*
//subtrees on both sides are of height 0, balance factor is thus 0

return 0;
};*/